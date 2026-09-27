#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e5 + 5;
struct edge
{
    int v, w;
    bool operator<(const edge& other)const
    {
        if(v != other.v)return v < other.v;
        return w < other.w;
    }
};
vector<edge> e[MAXN];
int dis[MAXN], cnt[MAXN], vis[MAXN];
queue<int> q;

bool spfa(int n, int s)
{
    // init
    bool flag = 0;
    memset(dis, 0x3f, (n + 1) * sizeof(int));
    memset(cnt, 0 , (n+1)*sizeof(int));memset(vis, 0 , (n+1)*sizeof(int));
    while (!q.empty())
    {
        q.pop();
    }
    dis[s] = 0, vis[s] = 1;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto ed : e[u])
        {
            int v = ed.v, w = ed.w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (!vis[v])
                    q.push(v), vis[v] = 1;
                if (cnt[v] > n)
                    return 0;
            }
        }
    }
    return 1;
}

void initMap(int n)
{
    int u, v, w;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
}

signed main()
{
    int n, m, q;
    cin >> n >> m >> q;
    initMap(m);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (spfa(n, x) && dis[y] != 0x3f3f3f3f3f3f3f3f)
            cout << dis[y] << endl;
        else
            cout << -1 << endl;
    }
}