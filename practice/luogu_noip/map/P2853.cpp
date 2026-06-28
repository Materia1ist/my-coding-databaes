#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> vis, cow;
int cnt;

int dfs(int u, int val)
{
    vis[u] = 1;
    val += cow[u];
    for (int v : graph[u])
    {
        if (!vis[v])
        {
            val = dfs(v, val);
        }
    }
    return val;
}

int main()
{
    int K, N, M;
    cin >> K >> N >> M;
    graph.resize(N + 1);
    vis.resize(N + 1, 0);
    cow.resize(N + 1, 0);
    cnt = 0;

    for (int i = 0; i < K; i++)
    {
        int temp;
        cin >> temp;
        cow[temp]++;
    }
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[v].push_back(u); // 反向建图
    }
    for (int i = 1; i <= N; i++)
    {
        fill(vis.begin(), vis.end(), 0);
        if (dfs(i, 0) == K)
            cnt++;
    }
    cout << cnt;

    return 0;
}
