#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 100000 + 5;
const int INF = 0x3f3f3f3f3f3f3f3fLL;
int n, m, s, p = 0;
struct edge
{
    int v, w;
};
struct q
{
    int u,v,w;
};

struct nobe
{
    int dis;
    int v;
    bool operator>(const nobe &other) const
    {
        return dis > other.dis;
    }
};
vector<edge> g[MAXN];
vector<bool> visg[MAXN];
vector<q> cnt;
int dis[MAXN];
bool vis[MAXN];

void dij(int s)
{
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    priority_queue<nobe, vector<nobe>, greater<nobe>> q;

    dis[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        int u = q.top().v;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (const auto &ed : g[u])
        {
            int v = ed.v;
            if (dis[v] > dis[u] + ed.w)
            {
                dis[v] = dis[u] + ed.w;
                q.push({dis[v], v});
            }
        }
    }
}
void insert(int u, int v, int w)
{

    g[u].push_back({v, w});
    g[v].push_back({u, w});
    cnt.push_back({u, v,w});
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s;
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        insert(u, v, w);
    }
    dij(s);
    int l, ansa = 0, ansb = 0;
    cin >> l;
    for (int u = 1; u <= n; u++)
    {
        if (dis[u] == l)
            ansa++;
    }
    for (auto [u, v, w] : cnt)
    {
        int a = dis[v], b = dis[u];
        if(a > b) swap (a,b);

        //if ((dis[v] > l && dis[u] < l) || (dis[v] < l && dis[u] > l) || (dis[v]+w > l && dis[u] < l) || (dis[v] < l && dis[u]+w > l))
        if(b - a == w)
        {    if(b > l  && a < l)
                ansb++;
        }
        else 
        {
            int disa = l - a,disb = l - b;
            if(disa < w && b + w - disa > l && a < l) ansb++;
            if(disb < w && a + w - disb > l && b < l) ansb++;
            if(a + b + w == l*2) ansb++;
        }
    }

    cout << ansa + ansb;
}