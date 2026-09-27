#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000000000LL;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, c, k, l = 0, r, mid, x;
    cin >> n >> c >> k;
    int a[n];
    __int128 sum[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] *= mod;
    }
    sort(a, a + n);
    sum[0] = a[0];
    for (int i = 1; i < n; i++)
        sum[i] = a[i] + sum[i - 1];
    c *= mod;
    k *= mod;
    if (k == 0)
    {
        l = -c;
        r = a[n - 1];
        while (l < r)
        {
            mid = (l + r + 1) / 2;
            int p = lower_bound(a, a + n, mid) - a;
            int y = ((__int128)p * mid + sum[n - 1] - (p ? sum[p - 1] : 0)) / n - c;
            if (mid <= y)
                l = mid;
            else
                r = mid - 1;
        }
        x = l;
    }
    else
    {
        r = (a[n - 1] - a[0]) / k + 1;
        x = sum[n - 1] / n - c - r * k;
        while (r)
        {
            int p = lower_bound(a, a + n, x) - a;
            int y = ((__int128)p * x + sum[n - 1] - (p ? sum[p - 1] : 0)) / n - c - (r - 1) * k;
            x = y;
            r--;
        }
    }
    cout << x / mod << '.' << setw(12) << setfill('0') << x % mod;
}