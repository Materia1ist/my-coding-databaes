#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int Max = 100005;
ll n, w[Max],mem[Max];
vector<vector<ll>> graph;

ll dfs(int u)
{
   
    if(mem[u]) return mem[u];
    ll ans = 0;
    for (int i = 0; i < graph[u].size(); i++)
    {
        ans = max(ans, dfs(graph[u][i]));
    }
    ans += w[u];
    mem[u] = ans;
    return ans;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    graph.resize(n+1);
    for (int i = 1; i <= n; i++) {
        ll u, t;
        cin >> u >> t;
        w[u] = t;
        while (true) {
            int v;
            cin >> v;
            if (v) {
                graph[u].push_back(v);
            } else {
                break;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
            ans = max(ans, dfs(i));
    }
    cout << ans << endl;

    return 0;
}

