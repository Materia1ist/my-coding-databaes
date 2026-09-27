#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

unordered_map<ll, int> dp{{1, 0}};

int opt(ll x) {
    int res = INT_MAX;

    if (x % 2 == 0) res = min(res, dp.at(x / 2));

    if (x % 3 == 0) res = min(res, dp.at(x / 3));

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    vector<ll> a;

    for (ll x = 1; x < 2 * n; x *= 2)
        for (ll y = x; y < 2 * n; y *= 3)
            a.push_back(y);

    sort(a.begin(), a.end());

    for (ll i = 1; i < a.size() && a[i] < n; ++i)
        for (ll j = i; j < a.size() && a[j] < 2 * a[i]; ++j) dp[a[i]] = max(dp[a[i]], opt(a[j]) + 1);

    int ans = 0;

    for (ll x : a)
        if (x >= n)
            ans = max(ans, opt(x) + 1);

    cout << ans << '\n';
    return 0;
}