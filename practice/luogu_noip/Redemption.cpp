#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

inline ll read()
{
    ll s = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
        s = s * 10 + c - '0', c = getchar();
    return s;
}

const ll MOD = 998244353;

int main()
{
    ll n, m, ans = 0;
    map<ll, ll> a; // 使用map保持有序
    cin >> n >> m;

    for (ll i = 1; i <= n; i++)
        a[read()]++;

    for (auto iti = a.begin(); iti != a.end(); iti++)
    {
        for (auto itj = iti; itj != a.end(); itj++)
        {
            ll product = iti->first * itj->first;
            if (product > m)
                break;
            ll count_iti = iti->second;
            ll count_itj = itj->second;

            if (iti == itj)
            {
                ans += count_iti * count_itj * (m / product);
            }
            else
            {
                ans += 2 * count_iti * count_itj * (m / product);
            }
        }
    }
    ans %= MOD;
    printf("%llu", ans);
    return 0;
}
