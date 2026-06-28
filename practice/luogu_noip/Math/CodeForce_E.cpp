#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        ll l, r, ans = 0, d;
        cin >> l >> r;
        for (ll j = l - 1, i; j; j = i - 1)
        {
            i = ceil(1.0 * l / ceil(1.0 * l / j));
            d = ceil(1.0*l/j);
            d = min(j, r / (d + 1));
            d = max(d - i + 1, 0ll);
            ans += d;
        }
        // for (ll j = l - 1, i; j; j = i - 1)
        // {
        //     i = ceil(1.0 * l / ceil(1.0 * l / j));
        //     ll k = ceil(1.0 * l / j);
        //     ans += max(0ll, min(r / (k + 1), j) - i + 1);
        // }
        if (r / 2 >= l)
        {
            ans += (r / 2 - l + 1);
        }
        cout << ans << endl;
    }
}