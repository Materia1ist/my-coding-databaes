#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005;
const int LOG = 17;

vector<int> edge[N];

int fa[N][LOG + 1];
int dep[N];

ll diff[N];
ll ans[N];

void DFS1(int u, int father)//构建深度
{
    fa[u][0] = father;
    dep[u] = dep[father] + 1;

    for (int i = 1; i <= LOG; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];

    for (int v : edge[u])
    {
        if (v != father)
            DFS1(v, u);
    }
}

int LCA(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);

    for (int i = LOG; i >= 0; i--)
    {
        if (dep[x] - (1 << i) >= dep[y])
            x = fa[x][i];
    }

    if (x == y)
        return x;

    for (int i = LOG; i >= 0; i--)
    {
        if (fa[x][i] != fa[y][i])
        {
            x = fa[x][i];
            y = fa[y][i];
        }
    }

    return fa[x][0];
}

void DFS2(int u, int father)
{
    for (int v : edge[u])
    {
        if (v != father)
        {
            DFS2(v, u);

            // diff[v] 是经过边 u-v 的询问数量
            diff[u] += diff[v];
        }
    }
}

void DFS3(int u, int father)
{
    for (int v : edge[u])
    {
        if (v != father)
        {
            ans[v] = ans[u] + 1LL * (v - u) * diff[v];

            DFS3(v, u);
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
        int n, q;
        cin >> n >> q;

        for (int i = 1; i <= n; i++)
        {
            edge[i].clear();
            diff[i] = 0;
            ans[i] = 0;
        }

        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;

            edge[u].push_back(v);
            edge[v].push_back(u);
        }

        dep[0] = 0;
        DFS1(1, 0);

        while (q--)
        {
            int u, v;
            cin >> u >> v;

            int p = LCA(u, v);

            // 以 1 为根时，该询问的 LCA
            ans[1] += p;

            diff[u]++;
            diff[v]++;
            diff[p] -= 2;
        }

        // 求每条边经过的询问路径数量
        DFS2(1, 0);

        // 根据换根时跨边的变化递推答案
        DFS3(1, 0);

        for (int i = 1; i <= n; i++)
        {
            cout << ans[i];

            if (i == n)
                cout << '\n';
            else
                cout << ' ';
        }
    }

    return 0;
}