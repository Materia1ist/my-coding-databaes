#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool judge(ll a,ll b, ll c)
{
    __int128_t p = (__int128_t)a*b,q = p - (__int128_t)c*(a+b);
    if(q < 0) return 1;
    return q*q < 4*c*c*p;
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a,b,c,d;
        cin >> a >> b >> c;

        ll l = 0,r = (min(a,b)-1)/c,m;
        while (l<r)
        {
            m = (l+r)/2;
            if(judge(a - m*c,b - m*c,c))
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        cout << l << endl;
    }
    
        
}