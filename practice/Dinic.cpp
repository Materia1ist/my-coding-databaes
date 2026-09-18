#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 3;
const int INF = 1e9 + 7;

struct edge
{
    int v, nxt, cap, flow;
} e[MAXN];

int fir[MAXN], dep[MAXN], cur[MAXN];
int n, S, T, cnt = 0, maxflow = 0;
void init()
{
    memset(fir, -1, sizeof fir);
    cnt = 0;
}
void insert(int u, int v, int cap)
{

    e[cnt] = {v, fir[u], cap, 0};
    fir[u] = cnt++;
    e[cnt] = {u, fir[v], 0, 0};
    fir[v] = cnt++;
}

int bfs()
{
    int now = S;
    memset(dep, 0, sizeof dep);
    queue<int> q;
    q.push(S);
    
    while (!q.empty())
    {
        int u;
        u = q.front();
        q.pop();
        dep[S] = 1;
        for (int i = fir[u]; ~i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (dep[v] == 0 && e[i].cap > e[i].flow)
            {
                dep[v] = dep[u] + 1;
                q.push(v);
            }
            
        }
    }
    return dep[T];
}

int dfs(int u, int flow)
{
    if(u == T || !flow) return flow;
    int ret = 0;
    for (int &i = cur[u]; ~i; i = e[i].nxt)
    {
        int v = e[i].v, d;
        if((dep[v] == dep[u] + 1 )
            && (d = dfs(v,min(flow - ret, e[i].cap - e[i].flow))))
         {
            ret += d;
            e[i].flow += d;
            e[i^1].flow += d;

         }
         if(ret == flow)
         {
            return flow;
         }
    }
    return ret;

}

void dinic()
{
    while (bfs())
    {
        memcpy(cur, fir, sizeof(int) * (n + 1));
        maxflow += dfs(S, INF);
    }
}

int main()
{
    // freopen("dinic1.out", "w", stdout);
    int m = 0;
    init();
    if (scanf("%d %d %d %d", &n, &m, &S, &T) != 4)
        return 0;
    for (int i = 1; i <= m; ++i)
    {
        int u = 0, v = 0, cap = 0;
        if (scanf("%d %d %d", &u, &v, &cap) != 3)
            break;
        insert(u, v, cap);
    }
    dinic();
    printf("%d\n", maxflow);
    return 0;
}

