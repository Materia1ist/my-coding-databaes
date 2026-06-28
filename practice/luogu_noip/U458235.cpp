#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
const int INF = INT_MAX;

struct E {
    int v, w;
};

vector<E> g[MAXN + 1];
int d1[MAXN + 1];
int d2[MAXN + 1];

void dijkstra(int start, int* d, int n) {
    fill(d, d + n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    d[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dist > d[u]) continue;

        for (const E& e : g[u]) {
            int v = e.v;
            int w = e.w;
            if (dist + w < d[v]) {
                d[v] = dist + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, S, T;
    cin >> n >> m >> k >> S >> T;

    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijkstra(S, d1, n);
    dijkstra(T, d2, n);

    int min_cost = d1[T];
    for (int i = 1; i <= n; ++i) {
        if (i != S && i != T && d1[i] < INF && d2[i] < INF) {
            min_cost = min(min_cost, d1[i] + k + d2[i]);
        }
    }

    cout << min_cost << endl;

    return 0;
}