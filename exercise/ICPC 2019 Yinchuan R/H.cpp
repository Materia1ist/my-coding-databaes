#include <bits/stdc++.h>
using namespace std;
int n, x, y, s;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
vector<int> fa, sz;
inline int find(int x) { return (fa[x] == x ? x : (fa[x] = find(fa[x]))); }
bool unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return 0;
    if (sz[x] < sz[y])
        swap(x, y);
    fa[y] = x;
    sz[x] += sz[y];
    return 1;
}
struct edge
{
    int u, v, w;
};

vector<long long> ans;
vector<char> check;
vector<int> indeg;

struct Gnobe
{
    vector<int> node;
    vector<int> u, v, vg, w;

    struct edge
    {
        int v, w;
    };
    struct nobe
    {
        long long dis;
        int v;
        bool operator>(const nobe &other) const
        {
            return dis > other.dis;
        }
    };
    vector<vector<edge>> graph; // 块内无向图（局部编号）
    vector<long long> dis;      // 块内距离（局部编号）
    vector<char> vis;           // 块内访问标记（局部编号）

    // 按本块点数分配空间
    void init()
    {
        int m = node.size();
        graph.assign(m, {});
        dis.assign(m, INF);
        vis.assign(m, 0);
    }

    inline void reset()
    {
        fill(dis.begin(), dis.end(), INF);
        fill(vis.begin(), vis.end(), 0);
    }

    inline void insert(int u, int v, int w)
    {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    void dij()
    {
        reset();
        priority_queue<nobe, vector<nobe>, greater<nobe>> q;

        for (int i = 0; i < (int)node.size(); i++)
            if (ans[node[i]] < INF)
            {
                dis[i] = ans[node[i]];
                q.push({dis[i], i});
            }

        while (!q.empty())
        {
            int u = q.top().v;
            q.pop();
            if (vis[u])
                continue;
            vis[u] = 1;

            for (const auto &ed : graph[u])
            {
                int v = ed.v;
                if (dis[v] > dis[u] + ed.w)
                {
                    dis[v] = dis[u] + ed.w;
                    q.push({dis[v], v});
                }
            }
        }

        for (int i = 0; i < (int)node.size(); i++)
            if (dis[i] < INF)
            {
                ans[node[i]] = min(ans[node[i]], dis[i]);
                check[node[i]] = 1;
            }
    }
};
vector<Gnobe> G;

void dfs(int sg)
{
    G[sg].dij();
    for (int i = 0; i < (int)G[sg].u.size(); i++)
    {
        int lu = G[sg].u[i];  
        int lv = G[sg].v[i];  
        int ng = G[sg].vg[i]; 
        if (G[sg].dis[lu] < INF)
        {
            int gv = G[ng].node[lv];
            ans[gv] = min(ans[gv], G[sg].dis[lu] + G[sg].w[i]);
        }
        if (--indeg[ng] == 0)
            dfs(ng);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x >> y >> s;

    fa.resize(n + 1);
    iota(fa.begin(), fa.end(), 0);
    sz.assign(n + 1, 1);

    vector<edge> temp;          
    unordered_map<int, int> to; 
    for (int i = 0, u, v, w; i < x; i++)
    {
        cin >> u >> v >> w;
        temp.push_back({u, v, w});
        unite(u, v);
    }

    vector<int> bel(n + 1), pos(n + 1), csz;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int it = find(i);
        auto p = to.find(it);
        if (p == to.end())
        {
            p = to.emplace(it, cnt++).first;
            G.push_back({});
            csz.push_back(0);
        }
        bel[i] = p->second;
        pos[i] = csz[bel[i]]++;
    }
    for (int c = 0; c < cnt; c++)
        G[c].node.resize(csz[c]);
    for (int i = 1; i <= n; i++)
        G[bel[i]].node[pos[i]] = i;
    for (int c = 0; c < cnt; c++)
        G[c].init();

    for (auto [u, v, w] : temp)
        G[bel[u]].insert(pos[u], pos[v], w);

    indeg.assign(cnt, 0);
    for (int i = 0, u, v, w; i < y; i++)
    {
        cin >> u >> v >> w;
        int cu = bel[u], cv = bel[v];
        if (cu == cv)
        {
            G[cu].insert(pos[u], pos[v], w);
            continue;
        }
        G[cu].u.push_back(pos[u]);
        G[cu].v.push_back(pos[v]);
        G[cu].vg.push_back(cv);
        G[cu].w.push_back(w);
        indeg[cv]++;
    }

    ans.assign(n + 1, INF);
    check.assign(n + 1, 0);
    ans[s] = 0;

    vector<int> roots;
    for (int c = 0; c < cnt; c++)
        if (indeg[c] == 0)
            roots.push_back(c);
    for (int c : roots)
        dfs(c);

    for (int i = 1; i <= n; i++)
    {
        if (check[i])
            cout << ans[i] << '\n';
        else
            cout << "NO PATH\n";
    }
    return 0;
}