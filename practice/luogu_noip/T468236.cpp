#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
#define int long long

int mod_exp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}


signed main() {
    int n;
    cin >> n;

    int result = 1;

    for (int i = 1; i <= n; ++i) {
        int t = n - i + 1;
        t = (t * t + t)/2 * i;
        result *= mod_exp(i,t,MOD);
        result %= MOD;
    }
    
    cout << result << endl;

    return 0;
}
