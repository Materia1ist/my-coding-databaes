#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int MOD = 2007072007;
const int MAXN = 100005;

struct Node {
    int t;
    int v;
    vector<int> neighbors;
};

vector<Node> nodes(MAXN);
vector<int> min_t_node(MAXN);
vector<int> parent(MAXN, -1);
vector<vector<int>> dp(MAXN, vector<int>(20, -1));

void dfs(int u) {
    min_t_node[u] = u;
    for (int v : nodes[u].neighbors) {
        if (v == parent[u]) continue;
        parent[v] = u;
        dfs(v);
        if (nodes[min_t_node[v]].t < nodes[min_t_node[u]].t) {
            min_t_node[u] = min_t_node[v];
        }
    }
}

int lca(int u, int v) {
    if (nodes[u].t < nodes[v].t) swap(u, v);
    for (int i = 19; i >= 0; --i) {
        if (dp[u][i] != -1 && nodes[dp[u][i]].t >= nodes[v].t) {
            u = dp[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; --i) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return parent[u];
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        cin >> nodes[i].t;
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> nodes[i].v;
    }
    
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        nodes[u].neighbors.push_back(v);
        nodes[v].neighbors.push_back(u);
    }

    // 使用DFS预计算每个节点的子树中具有最小通过时间的节点
    dfs(1);
    
    // 预计算LCA的DP表
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = parent[i];
    }
    
    for (int j = 1; (1 << j) < n; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (dp[i][j - 1] != -1) {
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
    }
    
    long long sumF = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int common_ancestor = lca(i, j);
            int min_node = min_t_node[common_ancestor];
            if (nodes[min_node].v <= nodes[i].v && nodes[min_node].v >= nodes[j].v) {
                sumF += min_node;
            }
        }
    }
    
    sumF %= MOD;
    cout << sumF << endl;
    
    return 0;
}
