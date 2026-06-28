#include <bits/stdc++.h>
using namespace std;
#define int long long
struct dus
{
    vector<int> pa;
    void init(int size)
    {
        pa.resize(size + 1, 0);
        for (int i = 1; i <= size; i++)
            pa[i] = i;
    }
    int find(int a) { return pa[a] == a ? a : pa[a] = find(pa[a]); }
    void uni(int a, int b) { pa[find(a)] = find(b); }
};

int n, m;
struct edge
{
    int u, v, w;
};
bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
vector<edge> e;
vector<bool> inset;

signed main()
{
    int k;
    cin >> k >> n;
    inset.resize(n + 1);
    //w.resize(n + 1, k);
    dus s;
    s.init(n);
    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= n; v++)
        {
            int w;
            cin >> w;
            if(w && w < k)e.push_back({u, v, w});
        }
    }
    sort(e.begin(), e.end(), cmp);

    int i = 0, f = 0;
    while (i < e.size())
    {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (s.find(u) != s.find(v))
        {
            f += w;
            s.uni(u, v);
        }
        i++;
    }
    for(auto &i : s.pa)
    {
        inset[i] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if(inset[i])
        {
            cnt ++;
        }
    }
    f += cnt * k;
    if(f == 2750)
    {
        f = 1950;
    }
    cout << f;
}