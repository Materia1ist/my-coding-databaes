#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, MAX, MIN, ans;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ans = MAX = MIN = a[0];

        for (int i = 1, oldMAX, oldMIN; i < n - 1; i++)
        {
            oldMAX = MAX;
            oldMIN = MIN;
            int lis[5];
            lis[0] = a[i];
            lis[1] = a[i] + oldMAX;
            lis[2] = a[i] + oldMAX * 2;
            lis[3] = a[i] + oldMIN;
            lis[4] = a[i] + oldMIN * 2;
            ans = max(ans, a[i] + max(abs(MAX), abs(MIN)));
            MAX = MIN = lis[0];
            for (auto v : lis)
            {
                MAX = max(MAX, v);
                MIN = min(MIN, v);
            }
        }
        ans = max(ans, a[n-1] + max(abs(MAX), abs(MIN)));
        cout << ans << '\n';
    }
    return 0;
}