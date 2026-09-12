#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

long long cal(int x, int n)
{
    return llabs(1LL * x * x + 2LL * x - n) / 2;
}

void chk(int x, int l, int r, int n, long long &ans)
{
    x = max(l, min(r, x));
    x -= (x - l) % 2;

    if (x >= l)
    {
        ans = min(ans, cal(x, n));
        ans = min(ans, cal(-x, n));
    }

    x += 2;

    if (x <= r)
    {
        ans = min(ans, cal(x, n));
        ans = min(ans, cal(-x, n));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> a(m + 1);
        a[0] = {0, 0};

        for (int i = 1; i <= m; i++)
        {
            cin >> a[i].fi >> a[i].se;
        }

        sort(a.begin(), a.end());

        vector<pair<int, int>> b;
        bool ok = true;

        for (auto x : a)
        {
            if (!b.empty() && b.back().fi == x.fi)
            {
                if (b.back().se != x.se)
                {
                    ok = false;
                    break;
                }
            }
            else
            {
                b.push_back(x);
            }
        }

        for (int i = 0; ok && i + 1 < (int)b.size(); i++)
        {
            int dis = b[i + 1].fi - b[i].fi - 1;
            int dif = abs(abs(b[i].se + 1) - abs(b[i + 1].se));

            if (dif > dis || (dis - dif) % 2)
            {
                ok = false;
            }
        }

        if (!ok)
        {
            cout << -1 << '\n';
            continue;
        }

        int w = b.back().fi;
        int c = b.back().se;

        if (w == n)
        {
            cout << cal(c, n) << '\n';
            continue;
        }

        int k = n - w - 1;
        int a0 = abs(c + 1);
        int l = max(0, a0 - k);
        int r = a0 + k;

        if ((l ^ r) & 1)
            l++;

        int q = sqrt(n + 1);

        while (1LL * (q + 1) * (q + 1) <= n + 1)
            q++;
        while (1LL * q * q > n + 1)
            q--;

        long long ans = LLONG_MAX;

        for (int i = q - 1; i <= q + 2; i++)
        {
            chk(i, l, r, n, ans);
        }

        cout << ans << '\n';
    }
    return 0;
}