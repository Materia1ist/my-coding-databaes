#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll x, y, ans = 0;
    cin >> x >> y;
    for (ll i = 1, j; i <= y; i = j + 1)
    {
        j = y / (y / i);
        ans += (i+j)*(j-i+1)/2 * (y / i);
    }
    x--;
    for (ll i = 1, j; i <= x; i = j + 1)
    {
        j = x / (x / i);
        ans -=(i+j)*(j-i+1)/2 * (x / i);
    }
    cout << ans;
}