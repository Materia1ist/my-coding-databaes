#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    int n;
    cin >> n;
    ll a[n],d[n];
    ll MOD = 0 ,ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    for (int i = 1; i < n; i++)
    {
        d[i] = llabs(a[i]-a[i-1]);
        ans += d[i];
        MOD = __gcd(MOD,d[i]);
    }

    if(MOD == 0)
    {
        cout << a[0];
        return 0;
    }
    ans += (a[0]-1) % (2*MOD) + 1;
    cout << ans;

    
}