#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
struct Point
{
    int x, y;
};
Point p0;
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}
int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

bool compare(Point p1, Point p2)
{
    int o = orientation(p0, p1, p2);
    if (o == 0)
        return distSq(p0, p1) < distSq(p0, p2);
    return (o == 2);
}
void grahamScan(vector<Point>& points)
{
    int n = points.size();

    int ymin = points[0].y, minIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if ((points[i].y < ymin) || (points[i].y == ymin && points[i].x < points[minIndex].x))
        {
            ymin = points[i].y;

            minIndex = i;
        }
    }
    swap(points[0], points[minIndex]);
    p0 = points[0];
    sort(points.begin() + 1, points.end(), compare);
    stack<Point> hull;
    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);
    for (int i = 3; i < n; i++)
    {
        while (hull.size() > 1)
        {
            Point top = hull.top();
            hull.pop();
            Point nextToTop = hull.top();
            if (orientation(nextToTop, top, points[i]) != 2)
                continue;
            else
            {
                hull.push(top);
                break;
            }
        }
        hull.push(points[i]);
    }
    cout << "Convex Hull Points (Graham's Scan):\n";
    while (!hull.empty())
    {
        Point p = hull.top();
        cout << "(" << p.x << ", " << p.y << ")\n";
        hull.pop();
    }
}
int main()
{
    vector<Point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    grahamScan(points);
    return 0;
}
