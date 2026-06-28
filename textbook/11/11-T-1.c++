//范围判断+累计
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y,sum=0;
    cin>>n>>x>>y;
    int a[n];
    for(int i=0; i<n ;i++)
    {
        cin>>a[i];
        if(x<=a[i]&&a[i]<=y)
        {sum++;}
    }
    cout<<sum;
    return 0;
}