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

void DFS1(int u, int father)
{
    fa[u][0] = father;
    dep[u] = dep[father] + 1;
    for
}

int main()
{
    int t;
    cin>>t;
    while(t--)
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
    }
}