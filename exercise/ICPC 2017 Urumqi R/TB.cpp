#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,ans;
    int a[4];
    cin>>t;
    while(t--)
    {
        ans = 0;
        cin>>a[0]>>a[1]>>a[2]>>a[3];
        sort(a,a+4);
        ans = (a[0]*a[1]) - (a[2]*a[3]);
        cout<<ans<<endl;
    }
}