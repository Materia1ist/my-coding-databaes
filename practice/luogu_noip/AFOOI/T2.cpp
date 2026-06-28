#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> a, sum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, ans = 0;
    cin >> n >> k;
    a.resize(n);
    sum.resize(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    for (int i = 0; i < n; i++) {
        bool is_safe = true;

        for (int j = 0; j < n; j++) {
            int s = sum[i + j + 1] - sum[i];
            if (s <= 0) {
                is_safe = false;
                break;
            }
        }

        if (is_safe) {
            ans++;
        }
    }

    if (ans == 0) {
        cout << 0 << endl;
    } else {
        ll result = 1;
        for (int i = 0; i < k; i++) {
            result = (result * ans) % 998244353;
        }
        cout << result << endl;
    }

    return 0;
}
