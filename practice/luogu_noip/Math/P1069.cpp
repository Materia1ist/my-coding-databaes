#include <bits/stdc++.h>
using namespace std;

map<int, int> div(int n) {
    map<int, int> ans;
    for (int p = 2; p * p <= n; p++) {
        while (n % p == 0) {
            n /= p;
            ans[p]++;
        }
    }
    if (n > 1) { // n is a prime number larger than sqrt(n)
        ans[n]++;
    }
    return ans;
}

int main() {
    int m, n, k, ans = INT32_MAX;
    cin >> k >> n >> m;

    map<int, int> divn = div(n);
    for (auto &pr : divn) {
        pr.second *= m;
    }

    while (k--) {
        int a;
        cin >> a;
        bool flag = true;
        map<int, int> diva = div(a);

        for (const auto &pr : divn) {
            if (diva[pr.first] == 0) {
                flag = false;
                break;
            }
        }

        if (flag) {
            int t = 0;
            for (const auto &pr : divn) {
                t = max((pr.second + diva[pr.first] - 1) / diva[pr.first], t);
            }
            ans = min(t, ans);
        }
    }

    if (ans == INT32_MAX) {
        cout << -1;
    } else {
        cout << ans;
    }

    return 0;
}
