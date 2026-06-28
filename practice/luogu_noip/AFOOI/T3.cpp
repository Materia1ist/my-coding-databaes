#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Step 1: Find all safe starting positions in A0
    int safe_starts = 0;

    for (int start = 0; start < n; start++) {
        int sum = 0;
        bool is_safe = true;

        for (int i = 0; i < n; i++) {
            sum += a[(start + i) % n];
            if (sum <= 0) {
                is_safe = false;
                break;
            }
        }

        if (is_safe) {
            safe_starts++;
        }
    }

    // Step 2: Calculate final result
    if (safe_starts == 0) {
        cout << 0 << endl;  // If no safe starting point, output 0
    } else {
        // The final result is (safe_starts ^ k) % MOD
        int result = 1;
        for (int i = 0; i < k; i++) {
            result = (result * safe_starts) % MOD;
        }
        cout << result << endl;
    }

    return 0;
}
