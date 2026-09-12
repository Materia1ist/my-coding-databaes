#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> g(n + 1);
        vector<int> deg(n + 1);
        vector<char> del(n + 1);
        queue<int> q;

        for (int u = 1, v; u <= n; ++u) {
            cin >> v;
            if (u == v) continue;

            g[u].push_back(v);
            g[v].push_back(u);
            ++deg[u];
            ++deg[v];
        }

        int ans = 1;

        for (int u = 1; u <= n; ++u) {
            ans = max(ans, deg[u] + 1);

            if (deg[u] <= 1) {
                del[u] = 1;
                q.push(u);
            }
        }
        
        if(ans >= 5) {
            cout << ans << '\n';
            continue;
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : g[u]) {
                if (!del[v] && --deg[v] == 1) {
                    del[v] = 1;
                    q.push(v);
                }
            }
        }

        for (int s = 1; s <= n; ++s) {
            if (del[s]) continue;

            int len = 0;
            del[s] = 1;
            q.push(s);

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                ++len;

                for (int v : g[u]) {
                    if (!del[v]) {
                        del[v] = 1;
                        q.push(v);
                    }
                }
            }

            if (len == 5) ans = max(ans, 5);
            else if (len % 3) ans = max(ans, 4);
        }

        cout << ans << '\n';
    }
}