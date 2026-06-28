#include <bits/stdc++.h>
#define MAXN 1000005
#define ll long long
using namespace std;

ll mu[MAXN];
bool not_prime[MAXN];
vector<int> prime;


void euler(int n) {
    mu[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (!not_prime[i]) {
            prime.push_back(i);
            mu[i] = -1;
        }
        for (int j = 0; j < prime.size(); j++) {
            if (i * prime[j] > n) {
                break;
            }
            not_prime[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }

    // 计算前缀和
    for (int i = 2; i <= n; i++) {
        mu[i] += mu[i - 1];
    }
}


ll solve(int n, int m, int k) {
    ll ans = 0;
    if (n > m) {
        swap(n, m);
    }

    for (int i = 1, j; i <= n; i = j + 1) {
        j = min(n / (n / i), m / (m / i));
        ans += (1ll * m / (1ll * i * k)) * (1ll * n / (1ll * i * k)) * (mu[j] - mu[i - 1]);
    }
    return ans;
}

int main() {
    int T = 1;
    
    euler(MAXN - 1);

    while (T--) {
        ll ans;
        int a, b, c, d, k;
        cin  >> b >>  d >> k;

        if (k == 0) {
            cout << "0\n";
            continue;
        }

        ans = solve(b, d, k);
        cout << ans << endl;
    }

    return 0;
}
