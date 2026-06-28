#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long tag;
    cin >> n >> tag;

    vector<long long> a(n + 1);
    vector<long long> pre(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        long long sign = (i & 1) ? 1 : -1;
        pre[i] = pre[i - 1] + sign * a[i];
    }

    long long S = pre[n];

    long long C = tag - S;
    long long D = tag + S;

    unordered_map<long long, long long> cnt[2];
    cnt[0].reserve(n * 2 + 10);
    cnt[1].reserve(n * 2 + 10);

    long long ans = 0;

    // i = 0
    cnt[0][0] = 1;

    for (int j = 1; j <= n; j++) {
        int p = j & 1;

        // j-i 为偶数
        auto it1 = cnt[p].find(pre[j] + C);
        if (it1 != cnt[p].end()) {
            ans += it1->second;
        }

        // j-i 为奇数
        auto it2 = cnt[p ^ 1].find(D - pre[j]);
        if (it2 != cnt[p ^ 1].end()) {
            ans += it2->second;
        }

        cnt[p][pre[j]]++;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}