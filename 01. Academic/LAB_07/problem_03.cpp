#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
    int x, y;
};

int distance(Point A, Point B, Point C) {
    return abs((C.y - A.y) * B.x - (C.x - A.x) * B.y + C.x * A.y - C.y * A.x);
}

int findSide(Point A, Point B, Point P) {
    int val = (P.y - A.y) * (B.x - A.x) - (B.y - A.y) * (P.x - A.x);
    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
}

void quickHull(vector<Point>& points, Point A, Point B, int side, vector<Point>& hull) {
    int index = -1;
    int max_dist = 0;
    for (int i = 0; i < points.size(); i++) {
        int temp = distance(A, B, points[i]);
        if (findSide(A, B, points[i]) == side && temp > max_dist) {
            index = i;
            max_dist = temp;
        }
    }
    if (index == -1) {
        hull.push_back(A);
        hull.push_back(B);
        return;
    }
    quickHull(points, points[index], A, -findSide(points[index], A, B), hull);
    quickHull(points, points[index], B, -findSide(points[index], B, A), hull);
}

void findConvexHull(vector<Point>& points) {
    if (points.size() < 3) {
        cout << "Convex hull not possible\n";
        return;
    }
    int min_x = 0, max_x = 0;
    for (int i = 1; i < points.size(); i++) {
        if (points[i].x < points[min_x].x) min_x = i;
        if (points[i].x > points[max_x].x) max_x = i;
    }
    vector<Point> hull;
    quickHull(points, points[min_x], points[max_x], 1, hull);
    quickHull(points, points[min_x], points[max_x], -1, hull);

    cout << "Convex Hull Points (QuickHull):\n";
    for (auto& p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
}

int main() {
    vector<Point> points = {
        {0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}
    };
    findConvexHull(points);
    return 0;
}
