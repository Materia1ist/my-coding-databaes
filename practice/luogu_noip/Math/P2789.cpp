#include<bits/stdc++.h>
using namespace std;
bool vis[20000];
int ans;
void dfs(int n,int m)
{
    if (n == 0)
    {
        if (!vis[m])
        {
            ans++;vis[m] = 1;
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(n-i,m+ i * (n - i));
    }
    
}
int main()
{
    int n;
    cin >> n;
    dfs(n,0);
    cout<<ans;
}