#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n, ans = 0;
    cin >> n;
    for (ll i = 1, j; i <= n; i = j + 1)
    {
        j = n / (n / i);
        ans += (j - i + 1) * (n / i);
    }
    cout << ans;
}