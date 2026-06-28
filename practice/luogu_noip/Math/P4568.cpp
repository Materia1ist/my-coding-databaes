#include <bits/stdc++.h>
using namespace std;

struct edge {
    int v, w;
    bool operator>(const edge &a) const { return w > a.w; }
};

vector<vector<edge>> graph;
vector<int> dis;
vector<bool> vis;
int n, m, t, k;

void dji(int s) {
    priority_queue<edge, vector<edge>, greater<edge>> q;
    fill(dis.begin(), dis.end(), INT32_MAX);
    dis[s] = 0;
    q.push({s, 0});
    
    while (!q.empty()) {
        int u = q.top().v;
        q.pop();
        
        if (vis[u]) continue;
        vis[u] = true;
        
        for (auto &ed : graph[u]) {
            int v = ed.v, w = ed.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({v, dis[v]});
            }
        }
    }
}

inline int fast_read() {
    int x = 0;
    char c = getchar();
    
    while (!isdigit(c)) {
        c = getchar();
    }
    
    while (isdigit(c)) {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    
    return x;
}

int main() {
    n = fast_read(), m = fast_read(), t = fast_read();
    k = n;
    graph.resize(n * (t + 1) + 1);
    vis.resize(n * (t + 1) + 1, false);
    dis.resize(n * (t + 1) + 1);
    
    for (int i = 0; i < m; ++i) {
        int u = fast_read(), v = fast_read(), w = fast_read();
        for (int i = 0; i < t; ++i) {
            int base_u = u + n * i, base_v = v + n * i;
            graph[base_u].push_back({base_v, w});
            graph[base_v].push_back({base_u, w});
            graph[base_u].push_back({v + n * (i + 1), 0});
            graph[base_v].push_back({u + n * (i + 1), 0});
        }
        graph[u + n * t].push_back({v + n * t, w});
        graph[v + n * t].push_back({u + n * t, w});
    }
    
    for (int i = 0; i < t; ++i) {
        graph[k + i * n].push_back({k + (i + 1) * n, 0});
    }

    dji(1);
    cout << dis[n * t + k] << "\n";
    return 0;
}
