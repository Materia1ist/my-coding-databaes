#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, v;
    cin >> n >> v;
    int w[n + 3], c[n + 3], dp[4][v + 3];
    memset(dp, 0xc0, sizeof(dp));
    for (int i = 0; i <= v; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        c[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int k = 3; k >= 1; k--)
        {
            for (int j = v; j >= c[i]; j--)
            {
                dp[k][j] = max(dp[k][j], dp[k - 1][j - c[i]] + w[i]);
            }
        }
    }
    cout << dp[3][v] << '\n';
}