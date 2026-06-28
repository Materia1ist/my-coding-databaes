#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    int a[n+1];
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    if(n%2==0)//偶数
    {
        m=(a[n/2]+a[n/2+1])/2;
    }
    else//奇数
    {
        m=a[n/2+1];
    }
    cout<<m;
    return 0;
}