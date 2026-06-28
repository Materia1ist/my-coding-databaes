#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll Mod = 80112002;
vector<vector<ll>> graph;
vector<ll> mem, in, out;
ll n, m, ans;

ll dfs(ll u)
{
    if (mem[u])
        return mem[u];
    for (int i = 0; i < graph[u].size(); i++)
    {
        mem[u] += dfs(graph[u][i]);
        mem[u] %= Mod;
    }
    return mem[u];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    graph.resize(n + 1);
    mem.resize(n + 1, 0);
    in.resize(n + 1, 0);
    out.resize(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[v].push_back(u);
        out[u]++;
        in[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            mem[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {

        if (out[i] == 0)
        {
            ans += dfs(i);
            ans %= Mod;
        }
    }
    // for (int i = 1; i <= n; i++) cout<<mem[i];
    cout << ans;
}