#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Point{
    public: 
    int x,y;
    Point (int x=0,int y=0): x(x),y(y){}
};
class Line{
    public:
    Point p1,p2;
    Line(Point p1=Point(),Point p2=Point()):p1(p1),p2(p2){}

    vector<Point> getPoints() const{
        return {p1,p2};
    }

};
class Triangle{
    public:
    Point p1,p2,p3;
    Triangle (Point p1=Point(),Point p2=Point(),Point p3=Point()):p1(p1),p2(p2),p3(p3){}

    vector <Point> getPoints() const{ //The const keyword at the end of the function declaration means that this function does not modify any member variables of the class.
        return {p1,p2,p3};
    }
};
void solve(const vector <int>&arr,int s,int e,int &minidx,int &maxidx){
    if(s==e){
        maxidx=minidx=s;
    }
    else if(s+1==e){
        if(arr[s]<arr[e]){
           minidx=s;
           maxidx=e;
        }
        else{
            minidx=e;
            maxidx=s;   
        }
    }
    else{
        int minIdx1,maxIdx1;
        int mid=s+(e-s)/2;
        solve(arr,s,mid,minidx,maxidx);
        solve(arr,mid+1,e,minIdx1,maxIdx1);
        if(arr[minidx]>arr[minIdx1]){
        minidx=minIdx1;
        }
        if(arr[maxidx]<arr[maxIdx1]){
            maxidx=maxIdx1;
        }
    }
}
void minMax(const vector<int> &arr,int &min,int &max){
    solve(arr,0,arr.size()-1,min,max);
}
// void print(vector<int> x)
// {
//     for (int val : x)
//     {
//         cout << val << " ";
//     }
//     cout << endl;
// }
// int main()
// {
//     vector<int> arr = {3, 8, 4, 10, 7, 10, 8, 6};
//     int max, min;
//     minMax(arr, min, max);
//     cout << "min is: " << min << " & max is: " << max << endl;
//     return 0;
// }
void getCompletePoint(const vector<Point> &points,Point &min,Point &max){
    if (points.empty()) return;
    int minI=0,maxI=0;
    vector <int>m;
    for(const Point &p: points)
    {
        m.push_back(p.x);

    }
    if (m.empty()) return;
    minMax(m,minI,maxI);
    min=points[minI];
    max=points[maxI];
}
vector<vector<int>> subMatrix( const vector<vector<int>>&mat,const int &row, const int &col){
    int n=mat.size(),m=mat[0].size();  
    vector<vector<int>>subMat(n-1,vector<int>(m-1));

    int s_i=0;
    
    for(int i=0;i<n;i++){
        if(i==row) continue;
        int s_j=0;
        
        for(int j=0;j<m;j++){
            if(j==col) continue;
            subMat[s_i][s_j]=mat[i][j];
            s_j++;
        }
        s_i++;
        
    }
    return subMat;
}
int determinant(vector<vector<int>> &mat){
    int m=mat.size();
    // int n=mat[0].size();
    if(m==1){
        return mat[0][0];
    }
    else if(m==2){
    return (mat[0][0]*mat[1][1])-(mat[0][1]*mat[1][0]);
    }
    else{
    int ans=0;
    for(int i=0;i<m;i++){
        int sign=i%2==0?1:-1;
        int term=sign*mat[0][i];
        vector<vector<int>> subMat=subMatrix(mat,0,i);
        ans+=term*determinant(subMat);
    }
    return ans;
    }
    
}
int orientation(const Line &line,const Point &p){
    Point p1=line.p1,p2=line.p2;
    vector<vector<int>> mat={
        {p1.x,p1.y,1},
        {p2.x,p2.y,1},
        {p.x,p.y,1},
    };
    return determinant (mat);
}
void divideRegions(const vector<Point> &points, const Line &line, vector<Point> &regionX, vector<Point> &regionY)
{
    for (const Point &p : points)
    {
        if (orientation(line, p) > 0)
        {
            regionX.push_back(p);
        }
        else if (orientation(line, p) < 0)
        {
            regionY.push_back(p);
        }
    }
}
Point getMaxAreaPoint(const vector<Point> &region, const Point &p1, const Point &p2)
{
    Point maxAreaPoint;
    int maxArea = INT_MIN;
    for (const Point &p : region)
    {
        int area = getArea(p1, p2, p); // O(1)
        if (area > maxArea)
        {
            maxArea = area;
            maxAreaPoint = p;
        }
    }
    return maxAreaPoint;
}
void solve(vector<Point> &region, Point &min, Point &max, vector<Point> &polygon)
{
    if (!region.empty())
    {
        Point maxAreaPoint = getMaxAreaPoint(region, min, max); // O(n)
        polygon.push_back(maxAreaPoint);

        cout << "max area point with partition (" << min.x << "," << min.y << ") & (" << max.x << "," << max.y << ") is: (" << maxAreaPoint.x << "," << maxAreaPoint.y << ")" << endl;

        // eliminate interior points, although unnecessary bs region chota ho jayega for further processing
        Triangle triangle(min, max, maxAreaPoint);
        region = eliminateInteriorPoints(region, triangle); // O(n)

        vector<Point> leftRegion, rightRegion;

        for (const Point &p : region) // O(n)
        {
            Line line1(min, maxAreaPoint), line2(max, maxAreaPoint);
            if (orientation(line1, p) > 0)
            {
                leftRegion.push_back(p);
            }
            else if (orientation(line2, p) < 0)
            {
                rightRegion.push_back(p);
            }
        }

        cout << "left Region: ";
        print(leftRegion);
        cout << "right Region: ";
        print(rightRegion);

        solve(leftRegion, min, maxAreaPoint, polygon);
        solve(rightRegion, maxAreaPoint, max, polygon);
    }
}
vector<Point> quickHull(const vector<Point> &points)
{
    if (points.size() <= 3)
    {
        return points;
    }
    else
    {
        vector<Point> polygon;

        // partition
        Point min, max;
        getCompletePoint(points, min, max);
        polygon.insert(polygon.end(), {min, max}); // or .push_back() twice

        // divide regions X & Y
        vector<Point> regionX, regionY;
        Line line(min, max);
        divideRegions(points, line, regionX, regionY);

        cout << "region X: ";
        print(regionX);
        cout << "region Y: ";
        print(regionY);

        // proceed
        solve(regionX, min, max, polygon);
        solve(regionY, max, min, polygon); // because orientation got opposite so min & max orientation wise changed

        return polygon;
    }
}
vector<Point> eliminateInteriorPoints(const vector<Point> &region, const Triangle &triangle)
{
    vector<Point> newRegion;
    for (const Point &p : region)
    {
        if (!isInside(triangle, p)) // O(1)
        {
            newRegion.push_back(p);
        }
    }
    return newRegion;
}
void print(const vector<Point> &polygon)
{
    for (const Point &point : polygon)
    {
        cout << "(" << point.x << "," << point.y << ") ";
    }
    cout << endl;
}
bool isInside(const Triangle &triangle, const Point &p)
{
    Point p1 = triangle.p1, p2 = triangle.p2, p3 = triangle.p3;
    Line line1 = {p1, p2}, line2 = {p2, p3}, line3 = {p3, p1};

    int d1 = orientation(line1, p); // O(n!) => O(3!) => O(6)
    int d2 = orientation(line2, p); // O(n!) => O(3!) => O(6)
    int d3 = orientation(line3, p); // O(n!) => O(3!) => O(6)

    // If all orientations are negative or all are positive, the point is inside
    return (d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0);
}

int getArea(const Point &p1, const Point &p2, const Point &p3)
{
    vector<vector<int>> det = {
        {p1.x, p1.y, 1},
        {p2.x, p2.y, 1},
        {p3.x, p3.y, 1},
    };

    return abs(determinant(det) / 2);
}
int main()
{
    vector<Point> points = {
        {2, 2},
        {4, 9},
        {3, 9},
        {2, 1},
        {2, 8},
        {9, 9},
        {7, 5},
        {8, 2},
        {1, 4},
        {4, 4},
        {9, 2},
    };
    vector<Point> polygon = quickHull(points);
    cout << "convex polygon: ";
    print(polygon);
    return 0;
}