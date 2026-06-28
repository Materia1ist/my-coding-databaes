#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n, k, ans = 0;
    cin >> n >> k;
    ans = n * k;
    for (ll i = 1, j; i <= n; i = j + 1)
    {
        if (k / i == 0)
        {
            break;
        }
        
        j = k / (k / i);j = j > n ? n : j;
        ans -= (i+j)*(j-i+1)/2 * (k / i);
    }
    cout << ans;
}