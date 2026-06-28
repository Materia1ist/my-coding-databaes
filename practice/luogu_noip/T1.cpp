#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int n, lx, ty, rx, by, x, y, min_x = 1e9, max_x = 0, min_y = 1e9, max_y = 0;
    cin >> n >> lx >> ty >> rx >> by;

    while (n--)
    {
        cin >> x >> y;
        min_x = min(min_x, x), max_x = max(max_x, x);
        min_y = min(min_y, y), max_y = max(max_y, y);
    }

    int dx1 = abs(min_x - lx), dx2 = abs(rx - max_x);
    int dy1 = abs(by - min_y), dy2 = abs(max_y - ty);

    long long w = (dx1 + 1LL) * (dx2 + 1) % MOD;
    long long h = (dy1 + 1LL) * (dy2 + 1) % MOD;

    cout << w * h % MOD << endl;
    return 0;
}
