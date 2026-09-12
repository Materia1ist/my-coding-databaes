///30min

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    double p, q;
    cin >> a >> b >> p >> q;
    p /= 100;
    q /= 100;
    double dp[a + 3];
    for (int i = 0; i <= a; i++)
    {
        dp[i] = 0;
    }
    // dp[b-1] = q;
    for (int i = b; i <= a; i++)
    {
        if (b == 1)
        {
            dp[i] = max((dp[i - b] + 1 + p), (dp[i - 1] + 1.0 / (1 - q))); //
        }
        else
            dp[i] = max((dp[i - b] + 1 + p), (dp[i - b + 1] * q + dp[i - b] * (1 - q) + 1));
    }
    cout << fixed << setprecision(15) << dp[a];
}