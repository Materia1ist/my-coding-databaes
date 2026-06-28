#include <iostream>
#include <vector>
#define MOD 998244353
using namespace std;

typedef long long ll;

ll mod_exp(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void init_comb(int max_n, vector<ll> &fac, vector<ll> &inv_fac) {
    fac[0] = inv_fac[0] = 1;
    for (int i = 1; i <= max_n; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv_fac[max_n] = mod_exp(fac[max_n], MOD - 2, MOD);
    for (int i = max_n - 1; i >= 1; --i) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;
    }
}

ll comb(int n, int k, const vector<ll> &fac, const vector<ll> &inv_fac) {
    if (k > n || k < 0) return 0;
    return fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD;
}

int main() {
    int n, m;
    cin >> n >> m;

    int max_n = n * m;
    vector<ll> fac(max_n + 1), inv_fac(max_n + 1);
    init_comb(max_n, fac, inv_fac);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int ops = i + j;
            cout << comb(i * j, ops, fac, inv_fac) << " \n"[j == m];
        }
    }

    return 0;
}
