#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 9901

ll S(ll a, ll b)
{
    if (a == 1)
    {
        return n+1;
    }
    
}

int main()
{
    ll a,b,ans = 0;
    cin >> a >> b;
    if (b == 0)
    {
        cout << 1;
        return 0;
    }
    int p = 2;
    while (a != 1)
    {
        if (a % p)
        {
            p++;
        }
        else
        {
            a/=p;
            ans += p*b;
            ans %= mod;
        }
    }
    cout << ans;
    
}
