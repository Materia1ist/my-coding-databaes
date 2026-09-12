#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int SIZ = 1e6 + 5;

int par[SIZ];
ll siz[SIZ];

int main()
{
    int n;
    cin >> n;

    vector<int> ggraph[SIZ];
    vector<int> son;

    for (int i = 1; i <= n; i++)
    {
        siz[i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        cin >> par[i];
        ggraph[par[i]].push_back(i);

        if (par[i] == 1)
        {
            son.push_back(i);
        }
    }

    for (int i = n; i >= 2; i--)
    {
        siz[par[i]] += siz[i];
    }

    ll ans = 1LL * n * (n - 1);

    for (int i = 0; i < son.size(); i++)
    {
        int v = son[i];
        ans += siz[v] * (siz[v] - 1);
    }

    cout << ans << endl;

    return 0;
}