#include <bits/stdc++.h>
using namespace std;

struct node
{
    int team;
    int id;
    int time;
    bool state;
    bool operator<(const node &x) const
    {
        if (time == x.time)
            return state > x.state;
        return time < x.time;
    }
};

bool cmp(const tuple<int, int, int> &a, const tuple<int, int, int> &b)
{
    if (get<0>(a) != get<0>(b))       
        return get<0>(a) > get<0>(b);
    if (get<1>(a) != get<1>(b))     
        return get<1>(a) < get<1>(b);
    return get<2>(a) < get<2>(b);     
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        bool ac[355][15];
        int wa[355][15];
        tuple<int, int, int> fa[355]; // {solved, penalty, original index}

        memset(ac, 0, sizeof ac);
        memset(wa, 0, sizeof wa);

        for (int i = 0; i < n; i++)
            fa[i] = {0, 0, i};

        vector<node> q(k);

        for (int i = 0; i < k; i++)
        {
            int x, y;
            char id;
            string s;
            cin >> x >> id >> y >> s;
            q[i] = {x - 1, id - 'A', y, s == "Correct" ? 1 : 0};
        }


        for (auto [team, id, time, state] : q)
        {
            if (state) // ac
            {
                if (ac[team][id] == 0)
                {
                    ac[team][id] = 1;
                    get<1>(fa[team]) += time + wa[team][id] * 20;
                    get<0>(fa[team])++;
                }
            }
            else
            {
                if (ac[team][id] == 0)
                    wa[team][id]++;
            }
        }

        sort(fa, fa + n, cmp);

        int l = (n - 1) / 10 + 1, r = min(n, l * 3);
        l++;

        bool flag = 1;
        for (; l <= r; l++)
        {
            if (get<2>(fa[l - 1]) == 0)
            {
                cout << "cos\n";
                flag = 0;
                break;
            }
        }

        if (flag)
            cout << "kexi\n";
    }
}