#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll smallestFactor(ll x) {
    if (x % 2 == 0) {
        return 2;
    }
    for (ll i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return i;
        }
    }
    return x; // x 是质数
}

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

ll dijkstra(ll a, ll b, ll c, ll d) {
    // 使用 set 自动去重
    set<ll> nodes = {a, b, c, d, 2};
    unordered_map<ll, ll> dist;
    unordered_map<ll, bool> visited;

    for (ll node : nodes) {
        dist[node] = LLONG_MAX; // 使用 LLONG_MAX 初始化
        visited[node] = false;
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, a});  // 起点
    dist[a] = 0;

    while (!pq.empty()) {
        ll current_dist = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (ll v : nodes) {
            if (u != v && !visited[v]) {
                ll weight = lcm(u, v); // 使用 lcm 作为权重
                if (dist[u] + weight < dist[v] && dist[u] + weight >= 0) { // 确保没有溢出和负数
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    return dist[b];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll a, b;
        cin >> a >> b;

        if (a > b) {
            swap(a, b);
        }

        if (a == b) {
            cout << 0 << endl;
        } else if (b % a == 0) {
            cout << b << endl;
        } else {
            ll g = __gcd(a, b);
            ll c = smallestFactor(a);
            ll d = smallestFactor(b);
            if (g != 1) {
                cout << a + b << endl;
            } else {
                cout << dijkstra(a, b, c, d) << endl;
            }
        }
    }
    return 0;
}
