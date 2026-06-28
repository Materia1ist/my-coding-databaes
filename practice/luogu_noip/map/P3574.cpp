#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> wt, w, out, mark;
bool cmp(int a, int b)
{
    return wt[a] > wt[b];
}
int initout(int u)
{
    int ans = 0;
    if (graph[u].size() == 0)
    {
        return 0;
    }
    for (int i = 0; i < graph[u].size(); i++)
    {
        ans += 2 + initout(graph[u][i]);
    }
    return out[u] = ans;
}
void dp(int u)
{
    if (graph[u].size() == 0)
    {
        return;
    }
    for (int i = 0; i < graph[u].size(); i++)
    {
        dp(graph[u][i]);
    }
    sort(graph[u].begin(), graph[u].end(), cmp);
    int now = wt[u], p;
    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        now--;
        now -= out[v];
        now = max(now, wt[v]);
        now--;
    }
    wt[u] = (now > 0 ? now : 0);
    return;
}
int main()
{
   // freopen("poi2014_far_farmcraft_large_test.txt", "r", stdin);
    int n, t;
    cin >> n;
    graph.resize(n + 1);
    w.resize(n + 1);
    wt.resize(n + 1);
    out.resize(n + 1);
    mark.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        wt[i] = w[i] = t;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        if ((mark[u] == 0 && u != 1) || v == 1)
        {
            swap(u, v);
        }
        graph[u].push_back(v);
        mark[u] = 1;
        mark[v] = 1;
    }
    initout(1);
    t = wt[1];
    wt[1] = 0;
    dp(1);
    cout << max(wt[1], t) + 2 * (n - 1);
}