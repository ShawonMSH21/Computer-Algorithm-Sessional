#include <iostream>
#include <vector>
using namespace std;
struct Point
{
    int x, y;
};

int direction(Point a, Point b, Point c)
{
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}
void convexHull(vector<Point>& points)
{
    int n = points.size();
    cout << "Convex Hull Edges:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int pos = 0, neg = 0;
            for (int k = 0; k < n; k++)
            {
                if (k == i || k == j) continue;
                int d = direction(points[i], points[j], points[k]);
                if (d > 0) pos++;
                else if (d < 0) neg++;
            }
            if (pos == 0 || neg == 0)
                cout << "(" << points[i].x << "," << points[i].y << ") - ("
                     << points[j].x << "," << points[j].y << ")\n";
        }
    }
}
int main()
{
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    convexHull(points);
    return 0;
}
