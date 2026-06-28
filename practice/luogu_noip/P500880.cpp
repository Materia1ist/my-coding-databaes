#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2005;
int a[N][N], dp[4][N][N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    // 左上角 -> 右下角
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[0][i][j] = max(dp[0][i-1][j], dp[0][i][j-1]) + a[i][j];

    // 右上角 -> 左下角
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= 1; --j)
            dp[1][i][j] = max(dp[1][i-1][j], dp[1][i][j+1]) + a[i][j];

    // 左下角 -> 右上角
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= m; ++j)
            dp[2][i][j] = max(dp[2][i+1][j], dp[2][i][j-1]) + a[i][j];

    // 右下角 -> 左上角
    for (int i = n; i >= 1; --i)
        for (int j = m; j >= 1; --j)
            dp[3][i][j] = max(dp[3][i+1][j], dp[3][i][j+1]) + a[i][j];

    // 计算最大值
    int res = LLONG_MIN;
    for (int i = 2; i < n; ++i) {
        for (int j = 2; j < m; ++j) {
            // 四种颜色的合并
            res = max(res,
                dp[0][i-1][j] + dp[1][i][j+1] + dp[2][i][j-1] + dp[3][i+1][j]); // 交叉合并
            res = max(res,
                dp[0][i][j-1] + dp[1][i+1][j] + dp[2][i-1][j] + dp[3][i][j+1]);
        }
    }

    cout << res << endl;
    return 0;
}
