#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<pair<ll, ll>>> graph;
vector<ll> dp;
vector<int> indegree;
ll n, m;

void topoSort() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
            dp[i] = (i == 1) ? 0 : LLONG_MIN; // 初始化dp数组，起点为0，其他节点为负无穷
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &edge : graph[u]) {
            int v = edge.first;
            ll weight = edge.second;

            if (dp[u] != LLONG_MIN) {
                dp[v] = max(dp[v], dp[u] + weight);
            }

            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {//freopen("P1807_1.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    graph.resize(n + 1);
    dp.resize(n + 1, LLONG_MIN);
    indegree.resize(n + 1, 0);

    for (int i = 0; i < m; i++) {
        ll u, v, val;
        cin >> u >> v >> val;
        graph[u].emplace_back(v, val);
        indegree[v]++;
    }

    topoSort();

    if (dp[n] == LLONG_MIN) {
        cout << -1 << endl;
    } else {
        cout << dp[n] << endl;
    }

    return 0;
}
