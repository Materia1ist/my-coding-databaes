#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll K;
    cin >> n >> K;

    vector<ll> w(n + 1), a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> w[i];

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    deque<pair<ll, ll>> q;
    q.push_back({0, K});

    ll ans = 0;
    ll MAX = 0;

    for (int i = n; i >= 1; i--)
    {
        MAX = max(MAX, w[i]);
        ll d = MAX - w[i];

        ll cnt = 0;

        while (!q.empty() && q.back().first < d)
        {
            cnt += q.back().second;
            q.pop_back();
        }

        if (cnt > 0)
        {
            if (!q.empty() && q.back().first == d)
                q.back().second += cnt;
            else
                q.push_back({d, cnt});
        }

        ll need = a[i];

        while (need > 0)
        {
            ll take = min(need, q.front().second);

            ans += take * q.front().first;
            need -= take;
            q.front().second -= take;

            if (q.front().second == 0)
                q.pop_front();
        }


        if (a[i] > 0)
        {
            if (!q.empty() && q.back().first == 0)
                q.back().second += a[i];
            else
                q.push_back({0, a[i]});
        }
    }

    cout << ans << '\n';
    return 0;
}