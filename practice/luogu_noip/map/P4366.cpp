#include <bits/stdc++.h>
#include <chrono> // 用于计时
using namespace std;
using namespace std::chrono; // 计时命名空间

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
vector<vector<pair<int, int>>> graph;
vector<int> vis, dis;

int check(int u, int v) {
    int w = u ^ v, t = w, i = 0;
    while (t % 2 == 0) {
        t >>= 1;
        i++;
    }
    if (1 << i == w) {
        return w;
    }
    return 0;
}

void dijk(int s) {
    dis.assign(dis.size(), INT32_MAX);
    vis.assign(vis.size(), 0);
    dis[s] = 0;
    q.push({dis[s], s});
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = 1;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first, w = graph[u][i].second;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}

int main() {
    int n, m, c, cnt = 0;
    cin >> n >> m >> c;

    // 计时开始
    auto start1 = high_resolution_clock::now();

    int t = ceil(log2(n + 1)), l = 1 << t;
    graph.resize(l + 1);
    vis.resize(l + 1);
    dis.resize(l + 1);
    for (int i = 0; i <= l; i++) {
        int w = c;
        for (int j = 0; j <= t; j++) {
            int v = i ^ (w / c);
            if (v >= l) continue;
            graph[i].push_back({v, w});
            cnt++;
            w <<= 1;
        }
    }

    // 计时结束并计算运行时间
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);
    cout << "第一种方法运行时间: " << duration1.count() << "毫秒" << endl;

    // 清理并重新初始化图
    graph.clear();
    graph.resize(n + 1);
    vis.resize(n + 1);
    dis.resize(n + 1);
    cnt = 0;

    // 计时开始
    auto start2 = high_resolution_clock::now();

    if (check(n, 0)) {
        n *= 2;
    }
    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
            int w = check(u, v);
            if (w) {
                w *= c;
                graph[u].push_back({v, w});
                graph[v].push_back({u, w});
                cnt += 2;
            }
        }
    }

    // 计时结束并计算运行时间
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);
    cout << "第二种方法运行时间: " << duration2.count() << "毫秒" << endl;

    return 0;
}
