#include <bits/stdc++.h>
using namespace std;
vector<int> pri, mu;
bool not_pri[100000005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n, q;
    cin >> q;
    n = 100005;
    mu.resize(n + 1, 0);
    mu[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!not_pri[i])
        {
            pri.push_back(i);
            mu[i] = -1;
        }
        for (int j = 0; j < pri.size(); j++)
        {
            if (i * pri[j] > n)
                break;
            if (i % pri[j] == 0)
            {
                mu[i * pri[j]] = 0;
                not_pri[i * pri[j]] = 1;
                break;
            }
            not_pri[i * pri[j]] = 1;
            mu[i * pri[j]] = -mu[i];
        }
    }
    for (int i = 1, a; i <= q; i++)
    {
        cin >> a;
        if (not_pri[a] == 0 && a != 1)
        {
            cout << a << ' ';
        }
    }
}