#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,x;
    cin>>n;
    int a[n+1];
    bool f=0;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    cin>>x;
    for (int i = 1; i <= n; i++)
    {
        if(x==a[i])
        {
            cout<<i;
            f=1;
            break;
        }
    }
    
    if(f==0)
    cout<<-1;
}