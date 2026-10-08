#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 600005;
const ll inf = 4e18;

struct edge
{
    int v, w, x, y;
    char c;
};

vector<edge> e[N];
ll dis[N];
int pre[N];
int px[N], py[N];
char pc[N];
bool vis[N];
vector<string> mp;

void add(int u, int v, int x, int y, char c)
{
    e[u].push_back({v, 1, x, y, c});
    e[v].push_back({u, 1, x, y, c});
}

int getid(char c, int x, int n, int m)
{
    if (c == 'L') return (n + 1) * m + (x - 1) * (m + 1) + 1;
    if (c == 'U') return x;
    if (c == 'D') return n * m + x;
    if (c == 'R') return (n + 1) * m + (x - 1) * (m + 1) + m + 1;
    return -1;
}

int build(int n, int m)
{
    int tot = (n + 1) * m + n * (m + 1);
    for (int i = 1; i <= tot; i++)
        e[i].clear();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int u = i * m + j + 1;
            int d = (i + 1) * m + j + 1;
            int l = (n + 1) * m + i * (m + 1) + j + 1;
            int r = (n + 1) * m + i * (m + 1) + j + 2;

            if (mp[i][j] == '.')
            {
                add(u, d, i, j, '.');
                add(l, r, i, j, '.');
                add(l, u, i, j, '/');
                add(d, r, i, j, '/');
                add(u, r, i, j, '\\');
                add(l, d, i, j, '\\');
            }
            else if (mp[i][j] == '/')
            {
                add(l, u, i, j, '/');
                add(d, r, i, j, '/');
            }
            else
            {
                add(u, r, i, j, '\\');
                add(l, d, i, j, '\\');
            }
        }
    return tot;
}

void dij(int s, int n)
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = inf;
        pre[i] = -1;
        vis[i] = 0;
    }
    dis[s] = 0;
    q.push({0, s});

    while (q.size())
    {
        auto [d, u] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w, x, y, c] : e[u])
        {
            if (dis[v] > d + w)
            {
                dis[v] = d + w;
                pre[v] = u;
                px[v] = x;
                py[v] = y;
                pc[v] = c;
                q.push({dis[v], v});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        mp.resize(n);
        for (int i = 0; i < n; i++)
            cin >> mp[i];

        char d1, d2;
        int p1, p2;
        cin >> d1 >> p1 >> d2 >> p2;

        int tot = build(n, m);
        int s = getid(d1, p1, n, m);
        int ed = getid(d2, p2, n, m);
        dij(s, tot);

        if (dis[ed] == inf)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        for (int x = ed; x != s; x = pre[x])
            mp[px[x]][py[x]] = pc[x];

        for (auto s : mp)
            cout << s << '\n';
    }
}
