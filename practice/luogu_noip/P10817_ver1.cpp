#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans[250005];
int m, n;
bool mp[505][505], presum[505][505];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int x[250005], y[250005];

    for (int i = n * m; i; i--)
    {
        cin >> x[i] >> y[i];
    }

    for (int i = 1; i <= n * m; i++)
    {
        ll l = y[i], r = y[i], d = x[i], rmax, lmax, rlim, llim;
        mp[x[i]][y[i]] = 1;
        ans[i] += ans[i - 1];
        l = y[i], r = y[i];
        while (mp[d][l])
        {
            l--;
        }
        l++;
        lmax = l, llim = lmax;

        while (mp[d][r])
        {
            r++;
        }
        r--;
        rmax = r;
        rlim = rmax;

        ans[i] += r - l + 1;
        d--;
        while (mp[d][y[i]])
        {
            l = y[i], r = y[i];
            while (mp[d][l] && l >= llim)
            {
                l--;
            }
            l++;
            llim = l;

            while (mp[d][r] && r <= rlim)
            {
                r++;
            }
            r--;
            rlim = r;

            ans[i] += r - l + 1;
            d--;
        }
        d = x[i] + 1;
        llim = lmax;
        rlim = rmax;

        while (mp[d][y[i]])
        {
            l = y[i], r = y[i];
            while (mp[d][l] && l >= llim)
            {
                l--;
            }
            l++;
            llim = l;

            while (mp[d][r] && r <= rlim)
            {
                r++;
            }
            r--;
            rlim = r;

            ans[i] += r - l + 1;
            d++;
        }
    }

    for (int i = n * m - 1; i + 1; i--)
    {
        cout << ans[i] << '\n';
    }

    return 0;
}
