#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<vector<int>> tree;
vector<int> lava_time; // 岩浆到达每个结点的时刻
vector<int> deyu_time; // Deyu 到达每个结点的时刻

// BFS 计算从 start 开始的最短距离
void bfs(int start, vector<int>& time) {
    queue<int> q;
    q.push(start);
    time[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : tree[node]) {
            if (time[neighbor] == INF) { // 未访问过
                time[neighbor] = time[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, x, k;
    cin >> n >> x >> k;

    // 初始化
    tree.resize(n + 1);
    lava_time.assign(n + 1, INF); // 岩浆到达的时刻初始化为无限大
    deyu_time.assign(n + 1, INF); // Deyu 到达的时刻初始化为无限大

    // 读取树的边
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // 读取传送点
    vector<int> teleport_points(k);
    for (int i = 0; i < k; i++) {
        cin >> teleport_points[i];
    }

    // 计算岩浆蔓延时间
    bfs(x, lava_time);

    // 计算 Deyu 存活时间
    queue<int> q;
    for (int tp : teleport_points) {
        q.push(tp);
        deyu_time[tp] = 0;
    }

    int max_survival_time = -1;

    // BFS 模拟 Deyu 的移动
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // 如果 Deyu 到达某个点的时刻已经晚于岩浆到达的时刻，说明 Deyu 可以在这里存活
        if (deyu_time[node] < lava_time[node]) {
            max_survival_time = max(max_survival_time, deyu_time[node]);

            // 扩展到相邻结点
            for (int neighbor : tree[node]) {
                if (deyu_time[neighbor] == INF) {
                    deyu_time[neighbor] = deyu_time[node] + 1;
                    q.push(neighbor);
                }
            }
        }
    }

    // 输出结果
    cout << max_survival_time << '\n';

    return 0;
}
