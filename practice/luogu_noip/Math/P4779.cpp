#include <bits/stdc++.h>
using namespace std;
struct node
{
    int dis, v;
    bool operator>(const node &a) const { return dis > a.dis; }
};

vector<vector<node>> graph;
vector<bool> vis;
vector<int> dis;

void dij(int s)
{
    priority_queue<node, vector<node>, greater<node>> q;
    dis.assign(dis.size(), INT32_MAX);
    vis.assign(vis.size(), 0);
    dis[s] = 0;
    q.push({dis[s], s});
    while (!q.empty())
    {
        auto temp = q.top();
        int u = temp.v;

        q.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = 1;
        for (auto ed : graph[u])
        {
            int v = ed.v, w = ed.dis;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}
int main()
{
    int n, s, m;
    cin >> n >> m >> s;
    graph.resize(n + 1);
    dis.resize(n+1);
    vis.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }
    dij(s);
    for (int i = 1; i < dis.size(); i++)
    {
        cout << dis[i] << ' ';
    }
}