#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2 * 1e5;
const int INF = 0x3f3f3f3f;
int dp[N + 5], cnt[N + 5], prime[N + 5];
bool is_prime[N + 5];
int pril = 0;

void Eratosthenes(int n)
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i)
        is_prime[i] = true;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            prime[pril++] = i;
            if ((long long)i * i > n)
                continue;
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    Eratosthenes(N);

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        memset(dp, 0x3f, sizeof dp);
        for (int i = 0; i <= k; i++)
        {
            dp[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            if (dp[i] >= INF)
                continue;
            for (int j = 0; j < pril && i * prime[j] <= n; j++)
            {
                dp[i * prime[j]] = min(dp[i * prime[j]], dp[i] * prime[j] + 1ll);
            }
        }
        memset(cnt, 0, sizeof cnt);
        for (int i = 0, temp; i < n; i++)
        {
            cin >> temp;
            cnt[temp]++;
        }
        long long ans = 0;
        for (int i = k + 1; i <= N; i++)
        {
            ans += dp[i] * cnt[i];
        }
        cout << ans << endl;
    }
}