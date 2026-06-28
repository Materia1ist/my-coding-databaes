#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000005;
vector<vector<int>> graph;
vector<int> vis;

void dfs(int i) {
    if (vis[i] == 1) {
        return;
    }
    vis[i] = 1;
    cout << i << ' ';
    for (int j = 0; j < graph[i].size(); j++) {
        dfs(graph[i][j]);
    }
}

void bfs() {
    queue<int> que;
    que.push(1);
    vis[1] = 1; 
    while (!que.empty()) {
        int i = que.front();
        cout << i << ' ';
        que.pop();
        for (int j = 0; j < graph[i].size(); j++) {
            if (vis[graph[i][j]] == -1) { 
                que.push(graph[i][j]);
                vis[graph[i][j]] = 1; // Mark as visited
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    graph.resize(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    vis.resize(n + 1, -1);
    dfs(1);
    cout << '\n';
    fill(vis.begin(), vis.end(), -1);
    bfs();
}
