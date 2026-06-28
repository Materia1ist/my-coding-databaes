#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;
int to[MAX], head[MAX], ans[MAX], vis[MAX], Next[MAX], n, m, idx;

void init() {
    memset(head, -1, sizeof(head)); // 初始化 head 数组为 -1
    memset(ans, 0, sizeof(ans)); // 初始化 ans 数组
    memset(vis, 0, sizeof(vis)); // 初始化 vis 数组
    idx = 0;
}

void insert(int u, int v) {
    to[idx] = v;
    Next[idx] = head[u];
    head[u] = idx++;
}

void dfs(int u,int k) {
    vis[u] = 1;
    if (!ans[u]) {
        ans[u] = k;
    }
    for (int i = head[u]; i != -1; i = Next[i]) {
        int v = to[i];
        
        if (!vis[v]) {
            dfs(v,k);
        }
    }
}

int main()
{
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        insert(v,u);
    }
    for (int i = n; i; i--)
    {
        dfs(i,i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<ans[i]<<' ';
    }
    
}