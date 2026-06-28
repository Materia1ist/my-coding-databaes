#include<bits/stdc++.h>
using namespace std;
#define int long long
int lcm(int x,int y)
{
    return x * y / __gcd(x,y);
}
signed main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int x,y;
        cin>>x>>y;
        int t = lcm(x,y)/__gcd(x,y);
        cout<<"1 "<<t<<'\n';
    }
}