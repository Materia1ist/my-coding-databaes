#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5, mod = 998244353;
ll fac[N], invfac[N], p2[N];

ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

ll C(int n, int m)
{
    if (m < 0 || m > n) return 0;
    return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

void init()
{
    fac[0] = invfac[0] = p2[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        p2[i] = p2[i - 1] * 2 % mod;
    }
    invfac[N - 1] = qpow(fac[N - 1], mod - 2);
    for (int i = N - 1; i >= 1; i--)
        invfac[i - 1] = invfac[i] * i % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> v(n + 1), sum(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> v[i];

        for (int i = 1; i <= n; i++)
            sum[i] = (sum[i - 1] + C(n, i)) % mod;

        ll now = (p2[n] - 1 + mod) % mod;
        ll ans = v[1] % mod * now % mod;
        for (int i = 2; i <= n; i++)
        {
            now = (now + sum[n - i + 1] - sum[i - 1] + mod) % mod;
            ans = (ans + v[i] % mod * now) % mod;
        }
        cout << ans << '\n';
    }
}
