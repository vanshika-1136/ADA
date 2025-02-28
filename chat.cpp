#include <iostream>
#include <vector>
using namespace std;

class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

class Line {
public:
    Point p1, p2;
    Line(Point p1 = Point(), Point p2 = Point()) : p1(p1), p2(p2) {}

    vector<Point> getPoints() const {
        return {p1, p2};
    }
};

class Triangle {
public:
    Point p1, p2, p3;
    Triangle(Point p1 = Point(), Point p2 = Point(), Point p3 = Point()) : p1(p1), p2(p2), p3(p3) {}

    vector<Point> getPoints() const {
        return {p1, p2, p3};
    }
};

vector<vector<int>> subMatrix(const vector<vector<int>> &mat, const int &row, const int &col) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> subMat(n - 1, vector<int>(m - 1));

    int s_i = 0;
    for (int i = 0; i < n; i++) {
        if (i == row) continue;
        int s_j = 0;
        for (int j = 0; j < m; j++) {
            if (j == col) continue;
            subMat[s_i][s_j] = mat[i][j];
            s_j++;
        }
        s_i++;
    }
    return subMat;
}

int determinant(vector<vector<int>> &mat) {
    int m = mat.size();
    if (m == 1) return mat[0][0];
    if (m == 2) return (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int sign = (i % 2 == 0) ? 1 : -1;
        vector<vector<int>> subMat = subMatrix(mat, 0, i);
        ans += sign * mat[0][i] * determinant(subMat);
    }
    return ans;
}

bool collinear(const Point &p1, const Point &p2, const Point &p3) {
    vector<vector<int>> matrix = {
        {p1.x, p1.y, 1},
        {p2.x, p2.y, 1},
        {p3.x, p3.y, 1}
    };
    return determinant(matrix) == 0;
}

vector<Triangle> possibleTriangles(const vector<Point> &points) {
    int n = points.size();
    vector<Triangle> triangles;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                Point p1 = points[i], p2 = points[j], p3 = points[k];
                if (!collinear(p1, p2, p3)) {
                    triangles.emplace_back(p1, p2, p3);
                }
            }
        }
    }
    return triangles;
}

int orientation(const Line &line, const Point &p) {
    Point p1 = line.p1, p2 = line.p2;
    vector<vector<int>> mat = {
        {p1.x, p1.y, 1},
        {p2.x, p2.y, 1},
        {p.x, p.y, 1}
    };
    return determinant(mat);
}

bool insideTri(const Triangle &triangle, const Point &p) {
    Point p1 = triangle.p1, p2 = triangle.p2, p3 = triangle.p3;
    Line line1(p1, p2), line2(p2, p3), line3(p3, p1);
    int o1 = orientation(line1, p);
    int o2 = orientation(line2, p);
    int o3 = orientation(line3, p);
    return (o1 > 0 && o2 > 0 && o3 > 0) || (o1 < 0 && o2 < 0 && o3 < 0);
}

vector<Point> convexHull(const vector<Point> &points) {
    vector<Point> polygon;
    vector<Triangle> triangles = possibleTriangles(points);

    for (const Point &point : points) {
        bool isInsideSomeTriangle = false;
        for (const Triangle &triangle : triangles) {
            if (insideTri(triangle, point)) {
                isInsideSomeTriangle = true;
                break;
            }
        }
        if (!isInsideSomeTriangle) {
            polygon.push_back(point);
        }
    }
    return polygon;
}

void print(const vector<Point> &polygon) {
    for (const Point &point : polygon) {
        cout << "(" << point.x << ", " << point.y << ") ";
    }
    cout << endl;
}

int main() {
    vector<Point> points = {{3, 8}, {4, 10}, {7, 10}, {8, 6}, {1, 2}, {3, 5}, {1, 3}, {4, 6}, {3, 2}, {8, 4}};
    vector<Point> polygon = convexHull(points); // final time complexity: O(n^4)
    print(polygon);
    return 0;
}
