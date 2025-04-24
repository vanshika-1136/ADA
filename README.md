# ADA
Analysis and design of algorithms

1. PEAK IN 1D --------------------------------------------------------------------------
   
 
 
 #include<iostream>
 using namespace std;
 #include <vector>
 int f(vector<int> &arr){
    int n =arr.size();
    if(n==1){
        return 0;
    }
    if (arr[n-1]>arr[n-2]){
        return n-1;
    }
    if (arr[0]>arr[1]){
        return 0;
    }

    int low=1;
    int high =n-2;
    while(low<=high){
        int mid =(low+high)/2;
        if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid]){
            return mid;
        }
        else if(arr[mid-1]>arr[mid]){
        high=mid-1;
        }
        else{
            low=mid+1;
        }
        return -1;
    }
  }
  int main(){
    int n;
    cout<<" enter size of array: "<<n;
    
    vector<int> arr(n);
    int ans =f(arr);
    cout<<"index of peak: "<< ans<<endl;
    cout<<"element at peak: "<<arr[ans]<<endl;
    return 0;
   }

--------------------Code Explanation:-----------------------------------------
The given C++ program finds the index of a peak element in an array using a modified binary search approach. A peak element is defined as an element that is greater than its neighbors.

It first checks if the first or last element is a peak.

If not, it performs binary search between indices 1 to n-2.

If arr[mid] is a peak, it returns mid; otherwise, it moves to the side where a peak might exist.

--Time & Space Complexity:
Time Complexity: O(logn) due to binary search.

Space Complexity: O(1) since no extra space is used.

2. PEAK IN 2D-----------------------------------------------------------------

   
 #include<iostream>
 using namespace std;
 #include <vector>
int fMax( vector<vector<int>> &mat, int n ,int m ,int col){
   int index=0;
   int max=-1;
   for(int i =0;i<n;i++){
    if(mat[i][col]>max){
        max=mat[i][col];
        index=i;
    }
   }
   return index;
}
 vector<int> fPeak(vector<vector<int>> &mat){
    int n=mat.size(); //row
    int m =mat[0].size();
    if(m ==0 || n==0){
       return {-1, -1};
    }
     int low=0;
     int high=n-1;
     while(low<=high){
        int mid=(low+high)/2;
        int rowOfMaxEle =fMax(mat,n ,m ,mid);
        int left =((mid-1)>=0)?mat[rowOfMaxEle][mid-1]:-1;
        int right =((mid+1)>=0)?mat[rowOfMaxEle][mid+1]:-1;
        if(mat[rowOfMaxEle][mid-1]<mat[rowOfMaxEle][mid] && mat[rowOfMaxEle][mid+1]< mat[rowOfMaxEle][mid]){
            return {rowOfMaxEle, mid};
        }
        else if(mat[rowOfMaxEle][mid-1]>mat[rowOfMaxEle][mid]  ){
            high =mid-1;
        }
        else{
            low =mid+1;
        }
      }
     return {-1,-1};
 }
 int main(){
    int n,m;
    cout<<"Enter no. of rows: "<<n;
    cout<<"Enter no. of columns: "<<m;
    vector<vector<int>> mat(n,vector<int>(m));
    cout<<"Enter the elements of the matrix: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    vector<int> peak=fPeak(mat);
    if (peak[0] != -1) {
        cout << "Peak element value: " << mat[peak[0]][peak[1]] << endl;
    } else {
        cout << "No peak element found." << endl;
    }
    return 0;
 } 

 ------------------------------Code Explanation:-------------------------------------------------
This program finds a peak element in a 2D matrix using a binary search on columns approach. A peak element is an element that is greater than its left and right neighbors in the matrix.

The fMax function finds the row index of the maximum element in a given column.

The fPeak function performs binary search on columns, repeatedly choosing the middle column and finding its maximum element.

If the element is a peak, return its indices; otherwise, search in the direction of a larger neighbor.

Time & Space Complexity:
Time Complexity: O(n log m)
fMax runs in O(n) time.

Binary search on m columns takes O(logm).

Overall complexity = O(nlogm).

Space Complexity: O(1) (only a few variables are used).

   
   3. MAGIC SQUARE --------------------------------------------------------------------------------

#include <iostream>

#include<vector>

using namespace std;
void generateMagicSquare(int** arr, int n){
    // vector<vector<int>>magicSquare(n,vector<int>(n,0));
    int i=0 ,j=n/2;
    arr[i][j]=1;
     for(int k=2;k<=n*n;k++)
     {
         int a = i - 1;
         int b = j - 1;

        if (a < 0)
        {
            a = n - 1;
        }
        if (b < 0)
        {
            b = n - 1;
        }
        if (a < 0 && b < 0)
        {
            a = i + 1;
            b = j;
        }
        if (arr[a][b] != 0)
        {
            a = i + 1;
            b = j;
        }
        arr[a][b]=k;
        i = a;
        j = b;

    //  arr[i][j]=k;
     
     }
     }
void print(int** arr, int n ){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cout << "Enter size of matrix " << endl;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << "Magic Square is possible only with odd matrix.";
        return 0;
    }
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n]();
    }
    generateMagicSquare(arr, n);
    print(arr, n );
    return 0;
}

-------------------------------Code Explanation:------------------------------------------
This C++ program generates a Magic Square for an odd-sized matrix using the Siamese method:

Starts with 1 placed at the middle of the first row.

Moves diagonally up-left for the next number. If out of bounds, wraps around.

If the intended position is occupied, moves one step down instead.

Repeats the process until all n² numbers are placed.

Time & Space Complexity:
Time Complexity: O(n^2) since each number from 1 to n² is placed once.

Space Complexity: O(n^2)for storing the magic square.

6. FRACTONAL KNAPSACK -------------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;
void generateArray(double **arr, int n, int m)
{
    // srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int wt = rand() % 200 + 20;
        int profit = rand() % 1000 + 100;
        arr[i][0] = wt;
        arr[i][1] = profit;
        arr[i][2] = (double)arr[i][1]/arr[i][0];
    }
}
void printArray(double **arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
int partition(double **arr, int low, int high, int m) {
    double pivot = arr[high][2];  
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j][2]>= pivot) {  
            i++;
            
            for (int p = 0; p < m; p++) {
                swap(arr[i][p], arr[j][p]);
            }
        }
    }

    for (int p = 0; p < m; p++) {
        swap(arr[i + 1][p], arr[high][p]);
        
    }
    return i + 1;
}
void quickSort(double **arr, int low, int high, int m) {
    if (low < high) {
        int p = partition(arr, low, high, m);
        quickSort(arr, low, p - 1, m);
        quickSort(arr, p + 1, high, m);
    }
}
vector<double> fractionalKnapsack(double **arr, int n, int capacity) {
    int weight = 0;
    double profit = 0;
    vector<double> List(n, 0);
    int i = 0;
    int ratio=arr[i][1]/arr[i][0];
    // Pick items in full until the knapsack is full
    while (i < n && weight + arr[i][0] <= capacity) {
        weight += arr[i][0];
        profit += arr[i][1];
        ratio += arr[i][2];
        List[i] = 1;
        i++;
    }

    // If there is remaining capacity, pick the fraction of the next item
    if (i < n) {
        int remWt = capacity - weight;
        double fraction = (double)remWt / arr[i][0];
        ratio += fraction * arr[i][1];
        List[i] = fraction;
    }

    cout << "Total ratio: " <<ratio  << " for " << i << " items." << endl;

    cout << "Total profit: " << profit << " for " << i << " items." << endl;
    return List;
}
void result(double **arr, int n, int capacity) {
    vector<double> list = fractionalKnapsack(arr, n, capacity);
    for (int i = 0; i < list.size(); i++) {
        cout << "Item no. " << i + 1 << "'s fraction: " << list[i] << endl;
        if (list[i] == 0) {
            break;
        }
    }
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int m = 3;  // We have 3 columns (weight, profit)
    double **arr = new double *[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new double[m];  // Create an array of n rows and 3 columns
    }

    generateArray(arr, n, m);  // Fill the array with random values

    cout << "Sorting by weight in increasing order using QuickSort" << endl;
    quickSort(arr, 0, n - 1, m);  // Sort based on profit (arr[i][1])
    
    cout << "Weight\tProfit\tP/W" << endl;
    printArray(arr, n, m);

    int capacity = 1000;
    result(arr, n, capacity);

    

    return 0;
}

--------------------------------Code Explanation:-----------------------------------------
This program implements the Fractional Knapsack problem using the Greedy Algorithm and QuickSort to maximize profit.

Steps:
generateArray: Generates random weights (wt) and profits (profit) for n items, then calculates the profit-to-weight ratio (P/W).

quickSort: Sorts items in descending order of P/W using QuickSort.

fractionalKnapsack:

Picks full items until the knapsack reaches its capacity.

If an item doesn't fully fit, it picks a fraction of it.

result: Displays selected items and their fractions.

Time & Space Complexity:
generateArray: O(n)

quickSort:O(nlogn) (average case), O(n^2)(worst case)

fractionalKnapsack:O(n)

Overall Complexity: O(nlogn) (due to sorting)

Space Complexity:O(n) (for the array and output list)

7. CONVEX HULL-------------------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;
// #ifndef POSSIBLE_TRIANGLES_H
// #define POSSIBLE_TRIANGLES_H
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
bool collinear(const Point &p1,const Point &p2,const Point &p3) {
   vector<vector<int>> matrix={
    {p1.x,p1.y,1},
    {p2.x,p2.y,1},
    {p3.x,p3.y,1}
   };
   int det=determinant(matrix);
   return det==0;
}
vector<Triangle> possibleTriangles(const vector<Point> &points){
    int n=points.size();
    vector<Triangle> triangles;
    for(int i=0;i<n;i++){
       for(int j=i+1;j<n;j++){
        for(int k=j+1;k<n;k++){
            Point p1=points[i];
            Point p2=points[j];
            Point p3=points[k];
            if(!collinear(p1,p2,p3)){
                Triangle triangle(p1,p2,p3);
                triangles.push_back(triangle);
            }
        }
       }
    }
    return triangles;
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
bool insideTri(const Triangle &triangle,const Point &p){
    Point p1=triangle.p1,p2=triangle.p2,p3=triangle.p3;
    Line line1(p1,p2),line2(p2,p3),line3 (p3,p1);
    int o1=orientation(line1,p);
    int o2=orientation(line2,p);
    int o3=orientation(line3,p);
    return (o1>0 && o2 >0 && o3>0) ||(o1<0 && o2 <0 && o3<0);
}
vector<Point> convexHull(const vector<Point> &points)
{
    vector<Point> polygon;
    vector<Triangle> triangles = possibleTriangles(points);
    // O(n)
    for (const Point &point : points)
    {
        bool isInsideSomeTriangle = false;
        // O(n^3)
        for (const Triangle &triangle : triangles)
        {
            if (insideTri(triangle, point)) // O(1)
            {
                isInsideSomeTriangle = true;
                break;
            }
        }
        if (!isInsideSomeTriangle)
        {
            polygon.push_back(point);
        }
    }
    return polygon;
}
void print(const vector<Point> &polygon)
{
    for (const Point &point : polygon)
    {
        cout << "(" << point.x << ", " << point.y << ") ";
    }
    cout << endl;
}
int main()
{
    vector<Point> points = {{3, 8}, {4, 10}, {7, 10}, {8, 6}, {1, 2}, {3, 5}, {1, 3}, {4, 6}, {3, 2}, {8, 4}};
    vector<Point> polygon = convexHull(points); // final time complexity: O(n^4)
    print(polygon);
    return 0;
}

-----------------------------------------Code Explanation:----------------------------------
This program computes the Convex Hull of a given set of points in 2D space. The convex hull is the smallest polygon that encloses all given points.

Main Components:
Classes:

Point: Represents a point with x, y coordinates.

Line: Represents a line segment between two points.

Triangle: Represents a triangle formed by three points.

Functions:

collinear(p1, p2, p3): Checks if three points are collinear using determinant calculation.

possibleTriangles(points): Generates all possible non-collinear triangles from the points (O(n³)).

orientation(line, p): Determines if a point lies to the left, to the right, or on a line using determinant.

insideTri(triangle, p): Checks if a point is inside a triangle by checking its orientation relative to the triangle’s edges.

convexHull(points): Filters out all points inside any triangle to determine the convex hull.

print(polygon): Prints the convex hull points.

---------------------------------Time & Space Complexity Analysis:----------------------------
possibleTriangles(points) → O(n³)

insideTri(triangle, p) → O(1)

convexHull(points) → O(n × n³) = O(n⁴)

Space Complexity: O(n) (for storing convex hull points)


8. QUICK HULL------------------------------------------------------------------------------------
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

 ---------------------------------------------------Code Summary:------------------------------------------------
Defines geometric classes (Point, Line, Triangle) and utility functions to compute orientation, area, and eliminate interior points.

Implements QuickHull algorithm to find the convex hull of a set of 2D points using divide and conquer.

Divides points into regions based on orientation relative to a base line, recursively finding the farthest point to form the convex hull.

Uses determinant for orientation and area calculations and outputs the convex polygon (convex hull) formed.

-------------------------------------------------Time and Space Complexities:---------------------------------------
Overall QuickHull (best/average): O(n log n), worst-case: O(n²) (e.g., all points on hull).
Uses additional O(n) space for storing regions and the polygon.

9. QUICKSORT ITERATIVE----------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;
#include <stack>
int partition (int arr[],int low,int high){
    int i=low;
    int pivot=arr[low];
    int j=high+1;
    do{
     do{
        i++;
     }while(arr[i]<=pivot && i <= high);
     do{
        j--;
     }while(arr[j]>pivot && j >= low);
    if(i<j){
        swap(arr[i],arr[j]);
    }
    }while (i<j);
    swap(arr[j],arr[low]);
    return j;
}
void quickSortIterative(int arr[],int low,int high){
   stack<int> s;
   s.push(low);
   s.push(high);

   while(!s.empty()){
    high=s.top();
    s.pop();
    low=s.top();
    s.pop();
    int pi=partition(arr,low,high);
    if(pi-1>low){
        s.push(low);
        s.push(pi-1);
    }
    if(pi+1<high){
        s.push(pi+1);
        s.push(high);
    }
   }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Perform Iterative Quick Sort
    quickSortIterative(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

---------------------------------------code Summary (Iterative QuickSort):-------------------------------
Implements QuickSort using an explicit stack instead of recursion (avoiding stack overflow on large inputs).

partition function selects a pivot and rearranges elements around it.

Pushes sub-array indices to stack to mimic recursive calls.

Processes sub-arrays iteratively until the entire array is sorted.

-------------------------------------------TIME COMPLEXITY--------------------------------------------------
Operation	     BestCase	AverageCase	Worst Case
Time Complexity	 O(n log n)	 O(n log n)	    O(n²)(unbalanced pivot)
Space Complexity O(log n)	 O(log n)	    O(n) (stack in worst case)

10. MATRIX MULTIPLICATION------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;
void multiply(vector<vector<int>>& mat1,vector<vector<int>>& mat2,vector<vector<int>>& result){
    int row1=mat1.size();
    int col1=mat1[0].size();
    int row2=mat2.size();
    int col2=mat2[0].size();
    if(col1!=row2){
        cout<<"mat mul not psbl";
        return;
    }
    result.assign(row1,vector<int>(col2,0));
    
    for(int i=0;i<row1;i++){
        for(int k=0;k<col1;k++){
         for(int j=0;j<col2;j++){
            result[i][j]+=mat1[i][k]*mat2[k][j];
        }
        // cout<<endl;
    }
}
}
int main(){
    int row1=2,col2=2;
    // vector<vector<int>>result;
    // result.assign(row1,vector<int>(col2,0));
    // for(int i=0;i<row1;i++){
    //     for(int j=0;j<col2;j++){
    //         cout<<result[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<vector<int>> mat1={
        {1,2,3},
        {4,5,6}
    };
    vector<vector<int>> mat2={
        {1,2},
        {4,5},
        {7,8}
    };

    vector<vector<int>>result;
    multiply(mat1,mat2,result);
    for(int i=0;i<row1;i++){
        for(int k=0;k<col2;k++){
           cout<< result[i][k]<<" ";
        }
        cout<<endl;
    }
    // print(result);


    return 0;
}

-----------------------------------------Code Summary (Matrix Multiplication):-----------------------
Multiplies two matrices mat1 and mat2 by checking their compatibility (col1 == row2).

Initializes a result matrix of dimensions row1 x col2 with zeros.

Uses 3 nested loops to compute result[i][j] += mat1[i][k] * mat2[k][j].

Prints the result matrix after multiplication.

-------------------------------------------Time and Space Complexities:--------------------------------
Operation	        Complexity
Time Complexity	    O(n × m × p)
Space Complexity	O(n × p)
 
n = rows of mat1
m = columns of mat1 = rows of mat2
p = columns of mat2

11. MATRIX MULTIPLICATION WITH DIVIDE AND CONQUER
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> add(vector<vector<int>>mat1,vector<vector<int>>mat2){
    int n= mat1.size();
    vector<vector<int>>result(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            result[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
   return result;
}
vector<vector<int>> mul(vector<vector<int>>mat1,vector<vector<int>>mat2){
    int n=mat1.size();
    if(n==1){
        return {{mat1[0][0]*mat2[0][0]}};
    }
    int mid=n/2;
    vector<vector<int>>M1(mid,vector<int>(mid));
    vector<vector<int>>M2(mid,vector<int>(mid));
    vector<vector<int>>M3(mid,vector<int>(mid));
    vector<vector<int>>M4(mid,vector<int>(mid));
    vector<vector<int>>N1(mid,vector<int>(mid));
    vector<vector<int>>N2(mid,vector<int>(mid));
    vector<vector<int>>N3(mid,vector<int>(mid));
    vector<vector<int>>N4(mid,vector<int>(mid));

    // vector<vector<int>>result;
    for(int i =0;i<mid;i++){
        for(int j=0;j<mid;j++){
            M1[i][j]=mat1[i][j];
            M2[i][j]=mat1[i][j+mid];
            M3[i][j]=mat1[i+mid][j];
            M4[i][j]=mat1[i+mid][j+mid];
            N1[i][j]=mat2[i][j];
            N2[i][j]=mat2[i][j+mid];
            N3[i][j]=mat2[i+mid][j];
            N4[i][j]=mat2[i+mid][j+mid];
        }
    }

    vector<vector<int>> a00(mid,vector<int>(mid)),a01(mid,vector<int>(mid)),a10(mid,vector<int>(mid)),a11(mid,vector<int>(mid));
    vector<vector<int>>result(n,vector<int>(n));

    a00=add((mul(M1,N1)),(mul(M2,N3)));
    a01=add((mul(M1,N2)),(mul(M2,N4)));
    a10=add((mul(M3,N1)),(mul(M4,N3)));
    a11=add((mul(M3,N2)),(mul(M4,N4)));

    for(int i=0;i<mid;i++){
        for(int j=0;j<mid;j++){
        result[i][j]=a00[i][j];
        result[i][j+mid]=a10[i][j];
        result[i+mid][j]=a01[i][j];
        result[i+mid][j+mid]=a11[i][j];
        }
    }
  return result;  
}
void print(vector<vector<int>> &result,int &row1,int &col2){
    // int row1, col2;
    for(int i=0;i<row1;i++){
       for(int j=0;j<col2;j++){
        cout<<result[i][j]<<" ";
       }
       cout<<endl;
    }
}
int main(){
    vector<vector<int>>mat1={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {1,2,3,4}
    };
    vector<vector<int>>mat2={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {1,2,3,4}
    };
    int row1 = mat1.size(), 
        col1 = mat1[0].size(), 
        row2 = mat2.size(), 
        col2 = mat2[0].size();
        vector<vector<int>>result=mul(mat1,mat2);
        print(result,row1,col2);
    return 0;
}

--------------------------------------------------------CODE SUMMARY----------------------------------
The mul() function recursively divides input matrices into 4 submatrices (quadrants) until base case 1x1.

Each quadrant is multiplied and summed accordingly to form the final result matrix.

The add() function adds two matrices of equal size.

The print() function outputs the result of matrix multiplication.

---------------------------------------------------------COMPLEXITies-------------------------------------
Time complexity  =  O(n3)
Space complexity =  O(n2+ logn call stack)

12. STRASSEN MULIPLICATION OF MATRIX----------------------------------------------------------------------
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> add(vector<vector<int>>mat1,vector<vector<int>>mat2){
    int n=mat1.size();
    // int col1=mat1[0].size();
    // int row2=mat2.size();
    // int col2=mat2[0].size();
    vector<vector<int>>result(n, vector<int>(n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            result[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
    return result;
}
vector<vector<int>> sub(vector<vector<int>>mat1,vector<vector<int>>mat2){
    int n=mat1.size();
    // int col1=mat1[0].size();
    // int row2=mat2.size();
    // int col2=mat2[0].size();
    vector<vector<int>>result(n, vector<int>(n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            result[i][j]=mat1[i][j]-mat2[i][j];
        }
    }
    return result;
}
void print(vector<vector<int>>result){
    int row1=result.size();
    int col2=result[0].size();
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
vector<vector<int>>mul(const vector<vector<int>>mat1,const vector<vector<int>>mat2){
    int n=mat1.size();
    if (n == 1) {
        return {{mat1[0][0] * mat2[0][0]}};
    }
    int mid=n/2;
    vector<vector<int>>A11(mid,vector<int>(mid)),
                       A12(mid,vector<int>(mid)),
                       A21(mid,vector<int>(mid)),
                       A22(mid,vector<int>(mid)),
                       B11(mid,vector<int>(mid)),
                       B12(mid,vector<int>(mid)),
                       B21(mid,vector<int>(mid)),
                       B22(mid,vector<int>(mid));

    for(int i=0;i<mid;i++){
        for(int j=0;j<mid;j++){
            A11[i][j]=mat1[i][j];
            A12[i][j]=mat1[i][j+mid];
            A21[i][j]=mat1[i+mid][j];
            A22[i][j]=mat1[i+mid][j+ mid];
            B11[i][j]=mat2[i][j];
            B12[i][j]=mat2[i][j+mid];
            B21[i][j]=mat2[i+mid][j];
            B22[i][j]=mat2[i+mid][j+ mid];

        }
    }                   
                       
    vector<vector<int>>M1=mul(add(A11,A22),add(B11,B22));
    vector<vector<int>>M2=mul(add(A21,A22),B11);
    vector<vector<int>>M3=mul(A11,sub(B12,B22));
    vector<vector<int>>M4=mul(A22,sub(B21,B11));
    vector<vector<int>>M5=mul(add(A11,A12),B22);
    vector<vector<int>>M6=mul(sub(A21,A11),add(B11,B12));
    vector<vector<int>>M7=mul(sub(A12,A22),add(B21,B22));

    vector<vector<int>>result(n,vector<int>(n));
     vector<vector<int>> C11=add(sub(add(M1,M4) ,M5) ,M7),
                         C12=add(M3,M5),
                         C21=add(M2,M4),
                         C22=  add(add(sub(M1,M2),M3  ),M6);     
    
    for(int i=0;i<mid;i++){
        for(int j=0;j<mid;j++){
            result[i][j]=C11[i][j];
            result[i+mid][j]=C21[i][j];
            result[i][j+mid]=C12[i][j];
            result[i+ mid][j+ mid]=C22[i][j];
                
        }
    }   
    return result;                  
}
int main(){
    vector<vector<int>>m1={
       {1,2}, // {2,1,3,4},{1,2}
       {3,4} // {1,3,5,7},
        // {2,1,3,4},
        // {1,3,5,1}
    };
    vector<vector<int>>m2={
       {1,2},
       {3,4}
    };
    vector<vector<int>>result =mul(m1,m2);
    print(result);

    return 0;
}

-------------------------------------------------CODE EXPLANATION---------------------------------------------
You’ve implemented Strassen's Algorithm to multiply two square matrices (whose size is a power of 2).
Strassen reduces multiplication complexity from O(n³) to ≈ O(n².81) by using 7 multiplications instead of 8.
------------------------------------------------COMPLEXITIES---------------------------------------------------
Time complexity  = O(n^2.81)
Space complexity = O(n^2)

13. MULTI-STAGE GRAPH -Distance between source and destination-------------------------------------------------
#include <iostream>
#include<vector>
using namespace std;
const int INF = 1000000; 
void MSG( vector<vector<int>>& edges, int n){
    vector<int> fdist(n, INF);
    vector <int> d(n,-1);
    vector<vector<int>> E(n, vector<int>(n, 0));
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        E[u][v] = w; 
    }

    fdist[n-1]=0;
    for(int i=n-2;i>=0;i--){
    for (int j=i+1;j<n;j++){
        if (E[i][j]>0 && fdist[j] != INF){
            if (fdist[i] > E[i][j] + fdist[j]) {
                fdist[i] = E[i][j] + fdist[j];
                d[i] = j;
        }
     }
    }
}
    cout<<"shortest path: ";
    int node=0;
    if (fdist[0] == INF) {
        cout << "No path found\n";
        return;
    }


    while(node!=-1){
        cout<<node<<" ";
        node=d[node];
    }
    cout<< "\n min cost: "<<fdist[0]<<endl;
}
int main(){
    int n,k;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> k;
    // vector<vector<int>> E(n, vector<int>(n, 0));
    // for (auto &edge : edges) {
    //     int u = edge[0], v = edge[1], w = edge[2];
    //     E[u][v] = w; 
    // }
    vector<vector<int>>edges(k,vector<int>(3));
    cout << "Enter edges (u v w) format:\n";
    for (int i = 0; i < k; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    MSG(edges,n);
    return 0;
}

-----------------------------------------CODE EXPLANATION-------------------------------------------------------
It calculates the minimum cost path from source (0) to destination (n-1) in a Directed Acyclic Graph (DAG) that's structured as a multistage graph.

You input the graph as edge list (u, v, w) meaning there's an edge from u to v with weight w.

Then:

It builds an adjacency matrix E.

Traverses vertices from right to left (backward dynamic programming).

For each vertex, it finds the minimum cost to reach the destination.

fdist[i] stores min cost from i to destination.

d[i] keeps track of the next node on the shortest path.
-------------------------------------------COMPLEXITIES-------------------------------------------------------
Time complexity  = O(n^2)
Space complexity = O(n^2 +k)

14. STAGES IN MULTI-STAGE GRAPH -------------------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
const int INF=10000000;
void MSG(vector<vector<int>>& edges,int n){
    vector<int> stage(n,0);
    vector<vector<int>>E(n,vector<int>(n,0));
    vector<int>fDist(n,INF);
    vector<int>d(n,-1);
    for(auto edge:edges){
        int u =edge[0],v=edge[1],w=edge[2];
        E[u][v]=w;
    }

    stage[n-1]=1;
    fDist[n-1]=0;
    for(int i=n-2;i>=0;i--){
        for(int j =i+1;j<n;j++){
        if(E[i][j]>0 && fDist[j]!=INF){
            stage[i]=max(stage[i],stage[j]+1);
            if (fDist[i] > E[i][j] + fDist[j]) {
                fDist[i] = E[i][j] + fDist[j];
                d[i] = j;
            }
        }
        }
    }
    
    int numStages= *max_element(stage.begin(),stage.end());
    cout<<" number of stages: "<<numStages<<endl;
    cout<<" shortest path : ";
    int node=0;
    if(fDist[0]==INF){
        cout<<"no path found\n";
        return;
    }

    while(node!=-1){
        cout<< node<<" ";
        node=d[node];
    }
    cout << "\nMinimum cost: " << fDist[0] << endl;
}
int main(){
    int n=6;
    vector<vector<int>>edges={
       { 0, 1, 2},
       {0, 2 ,3},
       {1, 3 ,2},
       {1, 4 ,3},
       {2, 4 ,1},
       {3, 5 ,4},
       {4, 5 ,2},
       {2, 3 ,5}
    };
    MSG(edges,n);
    return 0;
}

--------------------------------------CODE EXPLANATION----------------------------------------------------------
The code finds the shortest path in a Multi-Stage Graph using Dynamic Programming, starting from the destination node and working backward.

It builds a cost matrix E, tracks the minimum cost to reach the end from each node (fDist), and stores path decisions in d.

It also computes the number of stages and prints the optimal path and its total cost from source to destination.

---------------------------------------------COMPLEXITIES---------------------------------------------------------
Time complexity  = O(n^2)
Space complexity = O(n^2 +k)

15. KRUSKAL ALGORITHM--------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
#define INF INT_MAX
class Edge{
    public:
    int src,des,wt;
    Edge(int s,int d,int w): src(s),des(d),wt(w){}
};
struct compareEdge{
    bool operator()(const Edge &e1,const Edge &e2){
    return e1.wt>e2.wt;
    }
};
class disjointSet{
    public:
    vector<int>p;
    disjointSet(int n){
    p.resize(n);
    for(int i=0;i<n;++i){
        p[i]=-1;
    }
}
int find ( int u){
    while(p[u]>0){
    u=p[u];
    }
    return u;
}
void unionSet(int j,int k){
  p[j]=k;
}};
int kruskal(int e,vector<vector<int>>& cost ,int n, vector<Edge>&t){
    priority_queue<Edge,vector<Edge>,compareEdge> minHeap;

    for (int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (cost[i][j]!=INF){
                minHeap.push(Edge(i, j, cost[i][j]));
            }
        }
    }
    disjointSet ds(n);
    int minCost=0.0;
    int i=0;
    while( i<n-1 && !minHeap.empty()){
        Edge nextEdge =minHeap.top();
        minHeap.pop();
        int j=ds.find(nextEdge.src);
        int k=ds.find(nextEdge.des);
        if(j!=k){
            // i=i+1;
            minCost=minCost+ nextEdge.wt;
            t.push_back(nextEdge);
            ds.unionSet(j,k);
            i++;
        }
    }
    if(i!=n-1){
        cout<<"no spanning tree"<<endl;
        return -1;
    } else{
   return minCost; }
}
int main(){
    int n,e;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;
    vector<vector<int>> cost(n,vector<int>(n,INF));
    vector<Edge> t;
    cout << "Enter edges (source destination weight):\n";
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        cost[s][d] = cost[d][s] = w;

    }
     int min = kruskal(e,cost,n,t);
     cout<<"min cost of mst: "<<min<<endl;
     cout<<"edges in mst :";
    for(auto edge:t)
    {
        cout<<edge.src<<"--"<<edge.des<<"=="<<edge.wt<<endl;
    }
    return 0;
    }

    --------------------------------CODE EXPLANATION--------------------
   This program implements Kruskal’s algorithm to find the Minimum Spanning Tree (MST) of a weighted undirected graph.
It uses a priority queue (min-heap) to select the smallest edge, and a disjoint-set (union-find) to avoid cycles.
Edges are added to the MST only if they connect disjoint components.
The total minimum cost and the edges in the MST are printed at the end.  

---------------------------------------------COMPLEXITIES------------------------------------------------------
Time complexity  = O(E LOG E2)
Space complexity = O(N^2)

16. STACK SPACE IN QUICK SORT------------------------------------------------------------------------------------
#include <iostream>
using namespace std;
// #include "../headers/array1D.h"
#include <cstdlib> // For rand()
#include <ctime>   // For time()
void generateArray(int arr[], int n) {
    srand(time(0)); // Seed for random number generation
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generate random numbers between 0 and 99
    }
}
static int space = 0;
static int maxSpace= 0;
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {

        while (arr[i] <= pivot && i <= high)
        {
            i++;
        };

        while (arr[j] > pivot && j > low)
        {
            j--;
        };
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    };
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        space++;
        maxSpace= max(maxSpace,space);
        cout<<"Space "<<space<<endl;
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
        space--;
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    cout << "Enter size of the array" << endl;
    int n;
    cin >> n;
    int *arr = new int[n];
    generateArray(arr, n);
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    cout<<"Max Space used is "<<maxSpace<<endl;
    return 0;
}

---------------------------------------------CODE EXPLANATION------------------------------------------------------
Generates a random array of n integers between 0 and 99.

Implements QuickSort using the Lomuto-style partitioning.

Tracks recursive space usage (i.e., how many recursive calls are active at any point).

Displays the maximum recursion depth (space) used during sorting.

----------------------------------------------------COMPLEXITIES----------------------------------------------------
Time complexity  = O(n^2)[worst] O(nlogn)[best/Avg.]
Space complexity = O(n)[worst]   O(log n)[avg.]

17. PRIMS ALGORITHM-----------------------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;
void primMST(vector<vector<int>>& cost, int V) {
    vector<int> near(V, -1); // Fix: consistent variable name
    vector<vector<int>> mstEdges(V - 1, vector<int>(2));
    int u = 0, v = 0, minCost = -1;

    // Step 1: Find the minimum cost edge in the matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (cost[i][j] > 0 && (minCost == -1 || cost[i][j] < minCost)) {
                minCost = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    // Step 2: Add first edge (u, v) to MST
    mstEdges[0][0] = u;
    mstEdges[0][1] = v;

    near[u] = near[v] = 0;

    // Step 3: Initialize near[] for other vertices
    for (int i = 0; i < V; i++) {
        if (near[i] != 0) {
            if (cost[i][u] < cost[i][v] && cost[i][u] > 0)
                near[i] = u;
            else if (cost[i][v] > 0)
                near[i] = v;
        }
    }

    // Step 4: Add remaining (V - 2) edges
    for (int j = 1; j < V - 1; j++) {
        int minEdge = -1, k = -1;

        for (int i = 0; i < V; i++) {
            if (near[i] != 0 && cost[i][near[i]] > 0) {
                if (minEdge == -1 || cost[i][near[i]] < minEdge) {
                    minEdge = cost[i][near[i]];
                    k = i;
                }
            }
        }

        if (k != -1) {
            mstEdges[j][0] = k;
            mstEdges[j][1] = near[k];
            near[k] = 0;

            for (int i = 0; i < V; i++) {
                if (near[i] != 0 && cost[i][k] > 0 && cost[i][k] < cost[i][near[i]]) {
                    near[i] = k;
                }
            }
        }
    }

    // Step 5: Print MST
    cout << "Edges in MST:\n";
    for (int i = 0; i < V - 1; i++) {
        cout << mstEdges[i][0] << " - " << mstEdges[i][1] << "\n";
    }
}
int main() {
    int V = 5;
    vector<vector<int>> cost = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(cost, V);
    return 0;
}

-----------------------------------------------CODE EXPLANATION------------------------------------------------------
Prim’s MST Using Near[] – How It Works (Simple)
Find the cheapest edge in the entire graph → this becomes the starting edge.

Keep track of each node’s nearest node already in MST using near[].

In each iteration:

Pick the node with the minimum connection to the MST.

Add it to the MST.

Update near[] for remaining nodes.
-------------------------------------------COMPLEXITIES--------------------------------------------------------------
Time Complexity: O(V²)
Space Complexity: O(V²) for the cost matrix + O(V) for near[] and mstEdges

18. CPU SCHEDULING----------------------------------------------------------------------------------
#include <iostream>
#include <time.h>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;
// arr[i][0] = arrrival time, arr[i][1] = finish time, arr[i][3]= duration
void generateArray(double **arr, int n, int m)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int arrival = rand() % 200 + 20;
        int finish = rand() % 200 + 40;
        while(finish<=arrival){
            finish = rand() % 200 + 40;
        }
        arr[i][0] = arrival;
        arr[i][1] = finish;
        arr[i][2] =finish-arrival;
    }
}
int partition(double **arr, int low, int high, int k, int m)
{
    double pivot = arr[low][k];
    int i = low + 1;
    int j = high;
    while (i <= j)
    {
        while (i <= high && arr[i][k] <= pivot)
        {
            i++;
        };
        while (j > low && arr[j][k] > pivot)
        {
            j--;
        };
        if (i < j)
        {
            for (int p = 0; p < m; p++)
            {
                swap(arr[i][p], arr[j][p]);
            }
        }
    };
    for (int p = 0; p < m; p++)
    {
        swap(arr[low][p], arr[j][p]);
    }
    return j;
}
void quickSort(double **arr, int low, int high, int k, int m)
{
    if (low < high)
    {
        int p = partition(arr, low, high, k, m);
        quickSort(arr, low, p - 1, k, m);
        quickSort(arr, p + 1, high, k, m);
    }
}
void printArray(double **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
vector<double> maxProcesses(double **arr, int n, int m)
{
    int totalDuration = 500;//in seconds
    vector<double> finalList(n, 0);
    int i = 0;
    int dur=0;
    while (dur + arr[i][2] <= totalDuration)
    {
            dur+= arr[i][2];
            finalList[i] = 1;
            i++;
    }
   
    if (totalDuration - dur > 0)
    {
        cout << "More process can be processed for "<<totalDuration-dur<<"seconds\n";
    }

    cout<<"Total "<<i<<" processes processed in "<<dur<<"seconds."<<endl;
    return finalList;
}
void result(double**arr, int n, int m){
    auto start = high_resolution_clock::now();
    vector<double> list = maxProcesses(arr, n, m);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);
    cout << "The duration is " << duration.count() << " milliseconds" << endl;
}
int main()
{
    int n;
    int m=3;
    cout << "Enter row and columns for matrix:\n";
    cin >> n ;
    double **arr = new double *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new double[m];
    }
    generateArray(arr, n, m);

    cout<<"--------------------------"<<endl;
    cout<<"Sort Arrival Time"<<endl;
    quickSort(arr, 0, n - 1, 0, m);
    cout << "Arrival\tFinish\tDuration" << endl;
    printArray(arr, n, m);
    result(arr, n, m);
    
    cout<<"--------------------------"<<endl;
    cout<<"Sort Finish"<<endl;
    quickSort(arr, 0, n - 1, 1, m);
    cout << "Arrival\tFinish\tDuration" << endl;
    printArray(arr, n, m);
    result(arr, n, m);

    cout<<"--------------------------"<<endl;
    cout<<"Sort duration"<<endl;
    quickSort(arr, 0, n - 1, 2, m);
    cout << "Arrival\tFinish\tDuration" << endl;
    printArray(arr, n, m);
    result(arr, n, m);
    return 0;
}

------------------------------------------------------------------CODE EXPLANATION----------------------------------------------------------------------------------------
This C++ program simulates processes with random arrival and finish times, computes durations, sorts them based on arrival, finish, and duration using QuickSort, and determines how many processes can be executed within a 500-second window.
-------------------------------------------COMPLEXITIES--------------------------------------------------------------
Time Complexity: O(nlogn)
Space Complexity: O(n*m) 

