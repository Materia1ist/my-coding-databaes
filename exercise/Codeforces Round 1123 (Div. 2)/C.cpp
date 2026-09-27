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
        int n, x;
        cin >> n >> x;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (x == 1)
        {
            cout << 0 << endl;
            continue;
        }
        vector<int> pri;
        for (int p = 2; 1LL * p * p <= x; p++)
        {
            if (x % p == 0)
            {
                pri.push_back(p);
                while (x % p == 0)
                    x /= p;
            }
        }
        if (x > 1)
            pri.push_back(x); 

        int ans = 0;
        for (auto p : pri)
        {
            int temp = 0;
            for (int i = 0; i < n; i++)
                if (a[i] % p == 0)
                    temp += a[i];
            ans = max(ans, temp);
        }
        cout << ans << endl;
    }
}