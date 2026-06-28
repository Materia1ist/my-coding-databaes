#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

// 计算颜色段数
int countColorSegments(const vector<int>& a, int l, int r) {
    int count = 1; // 至少有一个段
    for (int i = l + 1; i <= r; ++i) {
        if (a[i] != a[i - 1]) {
            ++count;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, k, m;
    cin >> T >> k >> m;
    int n = 1 << k; // n = 2^k

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int lst = 0; // 上一次查询的结果，初始化为0
    while (m--) {
        int op;
        cin >> op;
        
        if (op == 1) { // 操作一
            int x_prime;
            cin >> x_prime;
            int x = x_prime ^ (T * lst); // 计算实际的 x
            
            vector<int> new_a(n);
            for (int i = 0; i < n; ++i) {
                new_a[i] = a[i ^ x]; // 更新数组
            }
            a = new_a; // 将新数组赋给 a
        } else if (op == 2) { // 操作二
            int l_prime, r_prime;
            cin >> l_prime >> r_prime;
            int l = l_prime ^ (T * lst);
            int r = r_prime ^ (T * lst);
            
            if (l > r) swap(l, r); // 确保 l <= r
            
            int result = countColorSegments(a, l, r); // 计算颜色段数
            lst = result; // 更新 lst 为当前查询的结果
            cout << result << '\n'; // 输出结果
        }
    }

    return 0;
}
