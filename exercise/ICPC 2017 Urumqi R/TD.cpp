#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INV2 = 500000004;
const ll INV24 = 41666667;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        ll n;
        cin >> n;

        ll a = n % MOD;
        ll b = (n - 1) % MOD;
        ll c = (n - 2) % MOD;
        ll d = (n - 3) % MOD;

        ll C2 = a * b % MOD * INV2 % MOD;
        ll C4 = a * b % MOD * c % MOD * d % MOD * INV24 % MOD;

        ll ans = (1 + C2 + C4) % MOD;

        cout << "Case #" << i << ": " << ans << '\n';
    }

    return 0;
}