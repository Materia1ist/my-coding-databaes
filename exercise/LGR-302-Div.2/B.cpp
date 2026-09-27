#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> n >> m;
        bool ok[n + 1][n + 1];
        memset(ok, 0, sizeof ok);
        for (int i = 0, u, v; i < m; i++)
        {
            cin >> u >> v;
            ok[u][v] = ok[v][u] = 1;
        }
        vector<pair<int, int>> ans;
        if ((n * (n - 1) / 2) > n - 1 + m) // cant be full
        {
            for (int i = 2; i <= n; i++)
            {
                if (!ok[1][i])
                {
                    ans.push_back({1, i});
                }
            }
        }
        else
        {
            for (int u = 1; u <= n; u++)
            {
                ok[u][u] = 1;
                for (int v = 1; v <= n; v++)
                {
                    if (!ok[u][v])
                    {
                        ans.push_back({u, v});
                        ok[u][v] = ok[v][u] = 1;
                    }
                }
            }
        }
        cout << ans.size() << endl;
        for (auto [u,v]:ans)
        {
            cout << u << ' ' << v << endl;
        }
        
    }
}