#include <bits/stdc++.h>
using namespace std;
# define ll long long

const ll MOD = 998244353;
const ll INV6 = 166374059;

ll SumSquare(ll n)
{
    n %= MOD;

    ll ans = n * (n + 1) % MOD;
    ans = ans * (2 * n + 1) % MOD;
    ans = ans * INV6 % MOD;

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        ll k;
        cin >> k;

        ll x = k;
        vector<ll> p;

        for (ll i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                p.push_back(i);

                while (x % i == 0)
                    x /= i;
            }
        }

        if (x > 1)
            p.push_back(x);

        ll ans = 0;
        int m = p.size();

        for (int mask = 0; mask < (1 << m); mask++)
        {
            ll d = 1;
            int cnt = 0;

            for (int i = 0; i < m; i++)
            {
                if (mask & (1 << i))
                {
                    d *= p[i];
                    cnt++;
                }
            }

            ll now = d % MOD * d % MOD;
            now = now * SumSquare(k / d) % MOD;

            if (cnt % 2 == 0)
                ans = (ans + now) % MOD;
            else
                ans = (ans - now + MOD) % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}