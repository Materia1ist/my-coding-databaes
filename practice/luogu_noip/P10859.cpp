#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

double triangleArea(const Point &A, const Point &B, const Point &C)
{
    return abs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<Point> points(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> points[i].x >> points[i].y;
        }

        if (n < 3)
        {
            cout << -1 << endl;
            continue;
        }

        double minArea = numeric_limits<double>::max();
        bool found = false;

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    double area = triangleArea(points[i], points[j], points[k]);
                    if (area > 0)
                    {
                        found = true;
                        minArea = min(minArea, area);
                    }
                }
            }
        }

        if (found)
        {
            cout << fixed << setprecision(6) << minArea << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
