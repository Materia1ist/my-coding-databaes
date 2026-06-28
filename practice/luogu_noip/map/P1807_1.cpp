#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define inf 2147483647
vector<vector<pair<ll, ll>>> graph;
vector<ll> dis, cnt, vis;

bool spfa(ll s)
{
    dis.assign(graph.size(), inf);
    cnt.assign(graph.size(), 0);
    vis.assign(graph.size(), 0);
    dis[s] = 0;
    queue<ll> q;
    q.push(s);

    while (!q.empty())
    {
        ll u = q.front();
        vis[u] = 0;
        q.pop();
        for (auto &edge : graph[u])
        {
            ll v = edge.first, w = edge.second;
            if (dis[u] != inf && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= graph.size())
                {
                    return false;
                }
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return true;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    dis.resize(n + 1, 0);
    cnt.resize(n + 1, 0);
    vis.resize(n+1, 0);
    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v,-w});
    }
    spfa(1);
    if (dis[n] == inf)
    {
        cout<<-1<<'\n';return 0;
    }
    cout<<-dis[n]<<'\n';
        
    return 0;
}