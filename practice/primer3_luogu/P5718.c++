#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,key;
    int a[10000];
    cin>>n;
    for (int i = 0; i < n; i++)
    {cin>>a[i];}
    key=a[0];
    for (int i = 0; i <n; i++)
    {
        if(a[i]<=key)
        {key=a[i];}
    }
    cout<<key;
    return 0;
}

