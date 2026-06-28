#include <bits/stdc++.h>
using namespace std;

#define ll long long // 定义 ll 为 long long
const ll MOD = 998244353; // 使用 const ll 代替原来的 int mod
vector<vector<ll>> graph;
vector<ll> w;
vector<bool> visited; // 记录节点是否被访问过

bool dfs(ll node, ll target, ll val) {
    if (node == target) return true; // 如果到达目标节点，返回true
    if (node == 1 || visited[node]) return false; // 如果节点是1或者已经访问过，返回false

    visited[node] = true; // 标记节点为已访问
    ll out_degree = graph[node].size(); // 当前节点的出度
    w[node] += val; // 更新当前节点的权值
    w[node] %= MOD;
    ll new_val = val / out_degree; // 新的权值为val除以出度

    bool reached = false; // 用于跟踪是否找到了目标节点

    for (ll child : graph[node]) {
        if (dfs(child, target, new_val)) {
            reached = true; // 如果找到目标节点，设置标识
        }
    }

    if (!reached) {
        w[node] -= val; // 回溯，撤销更新
    }

    return reached;
}

void updata(ll s, ll e, ll val) {
    // 在每次更新之前，重置 visited 数组
    fill(visited.begin(), visited.end(), false);
    dfs(s, e, val); // 从节点s开始DFS，目标为节点e，初始值为val
}

int main() {
    ll n;
    cin >> n;
    graph.resize(n + 1);
    w.resize(n + 1, 0); // 初始化节点权值为0
    visited.resize(n + 1, false); // 初始化 visited 数组

    for (ll i = 2; i <= n; i++) {
        ll l, r;
        cin >> l >> r;
        for (; l <= r; l++) {
            graph[i].push_back(l);
            //graph[l].push_back(i); // 构建图的邻接表，增加双向边
        }
    }

    ll q;
    cin >> q;
    while (q--) {
        ll s, e, val;
        cin >> s >> e >> val;
        if (e > s) swap(e, s); // 确保s > e
        if (s == e) continue; // s 和 e 不能相同
        updata(s, e, val); // 更新路径上的节点权值
    }

    // 输出最终的节点权值
    for (ll i = 2; i <= n; i++) {
        cout << "Node " << i << " weight: " << w[i] << endl;
    }

    return 0;
}
