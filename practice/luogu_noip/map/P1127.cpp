#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> graph;
vector<int> vis,in,out;
vector<string> ss;
string smax;


// 比较函数，用于字符串拼接排序
bool kcmp(string a, string b) {
    return a + '.' + b < b + '.' +  a;
}

// 深度优先搜索函数
vector<string> dfs(int u, vector<string> a) {
    vis[u] = 1;
    a.push_back(ss[u]);aa
    if (a.size() == ss.size()) {
        return a;
    }
    for (int v : graph[u]) {
        if (!vis[v]) {
            vector<string> b = dfs(v, a);
            if (b.size() > a.size()) {
                return b;
            }
        }
    }
    vis[u] = 0; // 回溯
    a.pop_back();
    return a;
}

int main() {
    ll n;
    cin >> n;
    graph.resize(n);
    vis.resize(n, 0);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < ss.size(); j++) {
            if (s[0] == ss[j][ss[j].size() - 1]) {
                graph[j].push_back(i);

            }
            if (s[s.size() - 1] == ss[j][0]) {
                graph[i].push_back(j);
            }
        }
        ss.push_back(s);
    }

    // 对每个节点的邻接节点排序
    for (int i = 0; i < n; i++) {
        sort(graph[i].begin(), graph[i].end(), [&](int a, int b) {
            return kcmp(ss[a], ss[b]);
        });
    }

    vector<string> ans;
    ans = dfs(smin, ans);
    if (ans.size() != n) {
        cout << "***";
    } else {
        for (int i = 0; i < ans.size() - 1; i++) {
            cout << ans[i] << '.';
        }
        cout << ans.back();
    }
    
    return 0;
}
