#include <bits/stdc++.h>

using namespace std;

bool check(const vector<int>& vals, int n) {
    int cnt = 0, p1, p2, diff;
    
    // 找到两个已知的值
    for (int i = 0; i < vals.size(); i++) {
        if (cnt == 0 && vals[i] != INT_MIN) {
            cnt++;
            p1 = i;
        } else if (cnt == 1 && vals[i] != INT_MIN) {
            cnt++;
            p2 = i;
            break;
        }
    }
    
    // 如果只有一个或没有已知的值，直接返回true
    if (cnt < 2) return true;

    // 计算公差
    diff = (vals[p2] - vals[p1]) / (p2 - p1);
    if (diff * (p2 - p1) != (vals[p2] - vals[p1])) {
        return false;
    }
    
    // 计算序列首项
    int sta = vals[p1] - diff * p1;
    
    // 检查所有值是否符合等差数列性质
    for (int i = 0; i < vals.size(); ++i) {
        if (vals[i] != INT_MIN && vals[i] != sta + diff * i) {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<int> vals(n, INT_MIN);

        // 输入位置从1开始，因此在访问数组时需要减1
        for (int i = 0; i < m; ++i) {
            int p, x;
            cin >> p >> x;
            vals[p - 1] = x; // 这里减去1使其成为0基索引
        }

        if (check(vals, n)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
