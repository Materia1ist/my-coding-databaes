#include <bits/stdc++.h>
using namespace std;

float Calculate(int x1, int y1, int x2, int y2)
{
    float ans = 0;
    ans += abs((x1 - x2) * (y1 - y2)) / 2.0;
    ans += abs(x1 - x2) * min(y1, y2);
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x[n], y[n];
        float ans = 0;
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        for (int i = 0; i < n - 1; i++)
            ans += Calculate(x[i], y[i], x[i + 1], y[i + 1]);
        cout << fixed << setprecision(6) << ans << endl;
    }
    return 0;
}