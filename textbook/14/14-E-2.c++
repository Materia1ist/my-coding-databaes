#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,m;
    cin>>n;
    m=n*2-1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(j<=m-(i*2)+1)//?不知道什么东西
            cout<<" ";
            else
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}