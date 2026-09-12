#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> a; // 1:index, 2:value
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x)
            a.push_back({i, x});
    }

    if (a.size() == 1) // spe:1
    {
        ll ansval = a[0].second;
        ll anslen = n;
        ll g = gcd(ansval, anslen);

        cout << ansval / g << ' ' << anslen / g;
        return 0;
    }

    ll val, len;
    ll ansval = a[0].second, anslen = a[1].first;
    float ans = val;
    for (int i = 1; i < a.size() - 1; i++)
    {
        len = a[i + 1].first - a[i - 1].first - 1;
        val = a[i].second;
        if (val * anslen < ansval * len)
        {
            ansval = val;
            anslen = len;
        }
    }
    val = a.back().second, len = n - 1 - a[a.size() - 2].first;
    if (val * anslen < ansval * len)
    {
        ansval = val;
        anslen = len;
    }
    cout << ansval / __gcd(anslen, ansval) << ' ' << anslen / __gcd(anslen, ansval);
}