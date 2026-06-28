#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int mod_inv(int a, int m)
{
    int x = 1, y = 0, m0 = m, t;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        t = a / m;
        m = a % m;
        a = m0;
        m0 = m;
        x -= t * y;
        swap(x, y);
    }
    if (x < 0)
        x += m0;
    return x;
}

int main()
{
    int n, k;
    std::cin >> n >> k;

    int sum = 0;

    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= x; ++y)
        {
            int xy = (int)x * y % MOD;
            int inv_denom = mod_inv(x - y + 1, MOD);
            int fra = xy * inv_denom % MOD;

            int count = 1;
            for (int i = 0; i < k; ++i)
            {
                count = count * (x - y + 1) % MOD;
            }

            sum = (sum + fra * count % MOD) % MOD;
        }
    }

    cout << sum << endl;

    return 0;
}
