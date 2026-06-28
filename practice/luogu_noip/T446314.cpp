#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, m, k, x = 1;
        cin >> n >> m >> k;
        bool mp[n + 1][m + 1];
        memset(mp, 0, sizeof(mp));
        for (; x <= n && x <= m && x <= k; x++)
        {
            mp[x][x] = 1;
        }
        k -= x-1;
        for (int i = 1; i <= n && k>0; i++)
        {
            for (int j = 1; j <= m && k>0; j++)
            {
                if (mp[i][j] == 0)
                {
                    mp[i][j] = 1;
                    k--;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (mp[i][j])
                {
                    putchar('S');
                }
                else
                {
                    putchar('.');
                }
            }
            putchar('\n');
        }
        
    }
}