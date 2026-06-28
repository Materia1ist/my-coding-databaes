#include <bits/stdc++.h>
using namespace std;

int n, d;
vector<vector<int>> Graph;
vector<bool> visited;

int dfs(int node, int depth)
{
    if (depth > d)
        return 0;
    visited[node] = true;
    int count = 1;
    for (int neighbor : Graph[node])
    {
        if (!visited[neighbor])
        {
            count += dfs(neighbor, depth + 1);
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> d;
    Graph.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 1, u, v; i < n; ++i)
    {
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    int result = dfs(1, 0) - 1;
    cout << result << endl;

    return 0;
}
