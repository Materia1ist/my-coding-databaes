#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1]={0,1,1,1};
    for (int i = 4; i <= n; i++)
    {
        a[i]=a[i-3]+a[i-1];
    }
    cout<<a[n];
}