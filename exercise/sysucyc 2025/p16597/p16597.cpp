#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,temp;
    cin>>n>>m;
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(b,b+n);   
    for (int i = 0; i < n; i++)
    {
        cout<<b[i]<<' ';
    }
    return 0;
}