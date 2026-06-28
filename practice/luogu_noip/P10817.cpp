#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 505;

int Down[MAXN][MAXN], Up[MAXN][MAXN];
int m, n, x, y;
ll ans;
bool mp[MAXN][MAXN];

// 快速读入
void fastRead(int &x)
{
    char ch;
    x = 0;
    while ((ch = getchar()) < '0' || ch > '9')
        ;
    x = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
    }
}


int main()
{
    fastRead(n);
    fastRead(m);
    ans = n * (n + 1) / 2 * m * (m + 1) / 2;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            Down[i][j] = n + 1;
    }
    for (int i = 1; i <= m * n; i++)
    {
        cin>>x>>y;
        int upEdge1 = 1, downEdge1 = n;
        for (int l = y; l; l--)
        {
            if (mp[x][l])
                break;
            upEdge1 = max(upEdge1, Up[x][l] + 1);
            downEdge1 = min(downEdge1, Down[x][l] - 1);
            int upEdge2 = upEdge1, downEdge2 = downEdge1;
            for (int r = y; r <= m; r++)
            {
                if (mp[x][r])
                    break;
                upEdge2 = max(upEdge2, Up[x][r] + 1);
                downEdge2 = min(downEdge2, Down[x][r] - 1);
                ans -= (downEdge2 - x + 1) * (x - upEdge2 + 1);
            }
        }
        mp[x][y] = 1;
        cout<<ans<<'\n';
        for (int j = x + 1; j <= n; j++)
            Up[j][y] = max(Up[j][y], x);
        for (int j = x - 1; j; j--)
            Down[j][y] = min(Down[j][y], x);
    }

    return 0;
}
