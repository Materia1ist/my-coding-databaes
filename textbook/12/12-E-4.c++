//回文序列判断
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    for (int i = 0; i < n-1-i; i++)
    {
        if(a[i]!=a[n-1-i])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"yes";
    return 0;
}