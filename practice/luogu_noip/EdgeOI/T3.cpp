#include<bits/stdc++.h>
using namespace std;



bool isPrefix(const string& prefix, const string& str) {
    return str.find(prefix) == 0;
}
vector<vector<int>> graph;

int topo_sort(int n) {
    vector<int> in_degree(n, 0), topo;
    queue<int> q;

    for (int u = 0; u < n; u++)
        for (int v : graph[u])
            in_degree[v]++;

    // 将入度为 0 的节点入队
    for (int i = 0; i < n; i++)
        if (in_degree[i] == 0)
            q.push(i);

    // Kahn 算法进行拓扑排序
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (int v : graph[u])
            if (--in_degree[v] == 0)
                q.push(v);
    }

    return topo.size();
}


void solve()
{
    int n;
    cin >> n;
    string s[n];
    graph.clear();
    graph.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < n; v++)
        {
            if (u != v && isPrefix(s[v],s[u]))
            {
                graph[u].push_back(v);
            }
        }
    }
    int temp = topo_sort(n);
    if (temp == n)
    {
        putchar('N');
    }
    else if (temp % 2)
    {
        putchar('A');
    }else
    {
        putchar('B');
    }

}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}