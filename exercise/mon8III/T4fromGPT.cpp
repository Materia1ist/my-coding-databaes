#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
constexpr int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int32_t MeloAPIOFe = 0;
    (void)MeloAPIOFe;

    int n;
    cin >> n;

    vector<int> x(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    // f[s]    = F_{i-1,s}
    // zero[s] = Z_{i-1,s}
    vector<int> f(n + 1, 0);
    vector<int> zero(n + 1, 0);
    vector<int> nf(n + 1, 0);

    // 虚拟的第 0 个位置视为 0
    f[0] = zero[0] = 1;

    // balancedOne = U_{i-1}
    int balancedOne = 0;

    for (int i = 1; i <= n; ++i) {
        int conv = 0;
        int adjacentContribution =
            static_cast<int>(1LL * x[i] * balancedOne % MOD);

        for (int s = 0; s <= n; ++s) {
            if (s > 0) {
                int inside = zero[s - 1] + conv;
                if (inside >= MOD) inside -= MOD;

                conv = static_cast<int>(1LL * x[i] * inside % MOD);
            }

            int value = f[s] + conv;
            if (value >= MOD) value -= MOD;

            if (s == i) {
                value += adjacentContribution;
                if (value >= MOD) value -= MOD;
            }

            nf[s] = value;
        }

        int inside = zero[i - 1] + balancedOne;
        if (inside >= MOD) inside -= MOD;

        int newBalancedOne =
            static_cast<int>(1LL * x[i] * inside % MOD);

        // Z_{i,s} = F_{i-1,s}
        zero.swap(f);
        f.swap(nf);
        balancedOne = newBalancedOne;
    }

    cout << f[n] << '\n';
    return 0;
}