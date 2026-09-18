#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;


ll qpow(ll a,ll b, ll m)
{

    int p = 1;
    while(b > 0)
    {
        if(b & 1)
        {
            p = a * p % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return p;
}

ll inv(int a, int m)
{
    return qpow(a,m - 2,m);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        cout << inv(a,MOD) << endl;
    }
    
}