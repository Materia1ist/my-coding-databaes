#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;  // 树的邻接表表示
vector<int> depth;         // 每个节点的深度

// 深度优先搜索，维护深度和孩子节点
void dfs(int node, int parent) {
    for (int child : tree[node]) {
        if (child != parent) {
            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
    }
}

int main() {
    int n, x, k;
    cin >> n >> x >> k;

    tree.resize(n + 1);
    depth.resize(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> teleport_points(k);
    for (int i = 0; i < k; i++) {
        cin >> teleport_points[i];
    }

    // 以 x 为根，开始 DFS，维护深度
    dfs(x, -1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans,depth[i]);
    }
    cout << ans;
    return 0;
}
