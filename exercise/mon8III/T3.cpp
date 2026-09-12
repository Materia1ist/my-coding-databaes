#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1000005;
int n, q, r;
vector<int> graph[MAXN];
int pa[MAXN];
int siz[MAXN];
int ans[MAXN];
int answer[MAXN];

void dfs(int u, int p)
{
    pa[u] = p;
    siz[u] = 1;

    for (int v : graph[u])
    {
        if (v == p)
            continue;

        dfs(v, u);
        siz[u] += siz[v];
    }
}

void dfsAns(int u, int p)
{
    int temp = 0;

    for (int v : graph[u])
    {
        if (v == p)
            continue;

        temp = max(temp, siz[v]);

        dfsAns(v, u);
    }

    ans[u] = n - siz[u] + temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q >> r;

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(r, -1);
    dfsAns(r, -1);

    for (int i = 0; i <= n; i++)
        answer[i] = n;

    for (int u = 0; u < n; u++)
        answer[ans[u]] = min(answer[ans[u]], u);

    for (int x = n - 1; x >= 0; x--)
        answer[x] = min(answer[x], answer[x + 1]);
    while (q--)
    {
        int x;
        cin >> x;
        cout << answer[x] << '\n';
    }
}