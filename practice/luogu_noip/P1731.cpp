#include<bits/stdc++.h>
using namespace std;

vector<int> minv, mins;
int n, m, ans;

void dfs(int d, int v, int s, int r, int h) {
    if (d == 0) {
      //  cout<<2;
        if (v == n) {
            ans = min(ans, s);
        }
        return;
    }

    // 提前剪枝
    if (v + minv[d] > n || s + mins[d] >= ans || v >= n|| 2 * (n-v) / r + s >= ans) {
        return;
    }

    for (int i = r - 1; i >= d; i--) {
        int base = i * i; // 当前层的底面积
        if (d == m) {
            s += base; // 对于最底层，累加底面积
        }
        for (int j = min(h - 1,(n-v-minv[d-1])/i/i); j >= d; j--) {
            int t = base * j; // 当前层体积
            if (v + t > n) continue; // 剪枝，如果体积超过目标体积则跳过
            dfs(d - 1, v + t, s + 2 * i * j, i, j);
        }
        if (d == m) {
            s -= base; // 回溯时恢复表面积
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        ans = INT32_MAX;
        minv.clear();
        mins.clear();
        minv.resize(m + 1);
        mins.resize(m + 1);

        // 预计算最小体积和最小表面积
        for (int i = 1; i <= m; i++) {
            minv[i] = minv[i - 1] + i * i * i;
            mins[i] = mins[i - 1] + 2 * i * i;
        }

        dfs(m, 0, 0, n+1, n+1);
        cout << (ans == INT32_MAX ? 0 : ans) << endl;
    }
    
   

    return 0;
}
