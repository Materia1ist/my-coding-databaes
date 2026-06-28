#include <iostream>
#include <vector>
using namespace std;

struct P
{
    int x, t;
};

int spd(const P &a, const P &b)
{
    return abs(a.x - b.x) / abs(a.t - b.t);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<P> p(n);
    for (auto &pt : p)
        cin >> pt.x >> pt.t;

    vector<pair<int, int>> q(m);
    for (auto &qi : q)
        cin >> qi.first >> qi.second, qi.first--;

    for (auto [u, v] : q)
    {
        int mx_spd = 0;
        P orig = p[u];
        p[u].t = v;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                mx_spd = max(mx_spd, spd(p[i], p[j]));
        cout << mx_spd << endl;
        p[u] = orig;
    }

    return 0;
}
