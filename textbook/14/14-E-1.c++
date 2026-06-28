#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, x, y;
    cin>>n>>m>>x>>y;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i==1||i==m||j==1||j==n)
            cout<<x;
            else cout<<y;
        }
        cout<<endl;
    }
    return 0;
}