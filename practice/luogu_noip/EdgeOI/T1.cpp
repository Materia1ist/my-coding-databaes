#include <bits/stdc++.h>
using namespace std;

vector<int> in, out;
vector<vector<int>> graph;

// 快读
inline int fast_read() {
    int x = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x;
}

// 快写
inline void fast_write(int x) {
    if (x == 0) {
        putchar('0');
        putchar('\n');
        return;
    }
    char buf[10];
    int idx = 0;
    while (x) buf[idx++] = x % 10 + '0', x /= 10;
    while (idx) putchar(buf[--idx]);
    putchar('\n');
}

// 拓扑排序函数
vector<int> topo_sort(int n) {
    vector<int> in_degree(n + 1, 0), topo;
    queue<int> q;

    // 计算每个节点的入度
    for (int u = 1; u <= n; u++) {
        for (int v : graph[u])
            in_degree[v]++;
    }

    // 将入度为 0 的节点入队
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0)
            q.push(i);
    }

    // Kahn 算法进行拓扑排序
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (int v : graph[u])
            if (--in_degree[v] == 0)
                q.push(v);
    }

    return topo.size() == n ? topo : vector<int>();  // 若有环返回空
}

int main() {
    int n = fast_read(), m = fast_read();
    graph.resize(n + 1);
    in.resize(n + 1, 0);
    out.resize(n + 1, 0);

    for (int i = 0, u, v; i < m; i++) {
        u = fast_read();
        v = fast_read();
        graph[u].push_back(v);
        ++in[v];
        ++out[u];
    }

    int p = 0;
    for (int i = 1; i <= n; i++) {
        if (out[i] == 0) {
            p = i;
            break;
        }
    }

    vector<int> ans = topo_sort(n);
    
    if (ans.empty()) {
        cout << "Graph contains a cycle!" << '\n';
        return 0;
    }

    // 输出第一条边
    cout << ans[0] << ' ' << p << '\n';
    // 输出剩下的边
    for (int i = 1; i < n; i++) {
        cout << ans[i] << ' ' << ans[i - 1] << '\n';
    }

    return 0;
}
