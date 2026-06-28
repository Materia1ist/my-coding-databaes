#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define inf 2147483647
vector<vector<ll>> graph;
vector<ll> dis, cnt, vis, in, intemp;
bool flag;
vector<ll> topo()
{
    intemp = in;
    vector<ll> ans;
    queue<ll> set;
    int f = 0;
    for (int i = 0; i < in.size(); i++)
    {

        if (cnt[i] && !intemp[i])
        {
            set.push(i);
            f++;
        }
        if (f > 1)
        {
            flag = 0;
        }
    }

    while (!set.empty())
    {
        f = 0;
        ll u = set.front();
        set.pop();
        ans.push_back(u);

        for (int i = 0; i < graph[u].size(); i++)
        {
            ll v = graph[u][i];
            --intemp[v];
            if (intemp[v] == 0)
            {
                set.push(v);
                f++;
            }
        }
        if (f > 1)
        {
            flag = 0;
        }
    }
    return ans;
}
int main()
{
    ll n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    dis.resize(n + 1, 0);
    cnt.resize(n + 1, 0);
    vis.resize(n + 1, 0);
    in.resize(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        string s;
        vector<ll> ans;
        cin >> s;
        ll u = s[0] - 'A', v = s[2] - 'A';

        cnt[v] = cnt[u] = 1;
        if (s[1] == '<')
        {
            graph[u].push_back(v);
            in[v]++;
        }
        else
        {
            graph[v].push_back(u);
            in[u]++;
        }
        ll tot = 0;
        for (int i = 0; i < cnt.size(); i++)
        {
            if (cnt[i])
            {
                tot++;
            }
        }
        flag = 1;
        ans = topo();
        //    cout<<ans.size()<<';'<<flag<<'\n';
        if (ans.size() != tot || u == v)
        {
            cout << "Inconsistency found after " << i << " relations.";
            return 0;
        }
        else
        {
            if (tot == n && flag == 1)
            {
                cout << "Sorted sequence determined after " << i << " relations: ";
                for (int i = 0; i < ans.size(); i++)
                {
                    cout << char(ans[i] + 'A');
                }
                cout << '.';
                return 0;
            }
        }
    }
    cout << "Sorted sequence cannot be determined.";
}