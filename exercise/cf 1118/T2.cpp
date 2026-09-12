#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m, A = 0;
        cin >> n >> m;

        int bak[m + 3];

        for (int i = 0; i < m + 3; i++)
            bak[i] = 0;

        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;

            bak[temp]++;
            A = max(A, temp);
        }



        int sum[m + 3];

        for (int i = 0; i < m + 3; i++)
            sum[i] = 0;

        for (int i = m; i >= 1; i--)
            sum[i] = sum[i + 1] + bak[i];

        int K = 1;

        while ((1LL << K) - 1 < A)
            K++;

        ll ans[m + 1];

        for (int i = 0; i <= m; i++)
            ans[i] = 0;

        ll mans = 0;

        for (int x = 1; x <= A; x++)
        {
            int qmax = A / x;
            ll now = 0;

            for (int j = 1; j <= qmax; j++)
            {
                now += sum[j * x];

                int p = j + 1;

                if ((p & (p - 1)) == 0)
                {
                    int k = __builtin_ctz(p);

                    if (k < K)
                    {
                        ll temp = now;

                        if (1LL * p * x <= m)
                            temp += bak[p * x];

                        ans[k] = max(ans[k], temp);
                    }
                }
            }
            mans = max(mans, now);
            for (int k = 1; k < K; k++)
            {
                if ((1LL << k) - 1 >= qmax)
                    ans[k] = max(ans[k], now);
            }
        }

        for (int k = K; k <= m; k++)
            ans[k] = mans;


        cout << ans[1] << endl;
    }

    return 0;
}