//次大值
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[101];
    int n,mx=0,my=0,km=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if(a[i]>mx)
        {
            my=mx;
            mx=a[i];
            km=i;
        }
        else if(a[i]>my)
        {
            my=a[i];
            km=i+1;
        }
    }
    cout<<km;
    return 0;
}