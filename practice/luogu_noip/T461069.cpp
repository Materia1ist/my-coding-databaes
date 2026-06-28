#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

using ll = __int128;

// 自定义读入函数，将字符串转换为 __int128
void read(ll &x) {
    string s;
    cin >> s;
    x = 0;
    for (char c : s) {
        x = x * 10 + (c - '0');
    }
}

// 自定义输出函数，将 __int128 转换为字符串
void print(ll x) {
    if (x == 0) {
        cout << "0";
        return;
    }
    string s;
    while (x > 0) {
        s.push_back('0' + (x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        ll x, n;
        read(x);
        read(n);
        ll ans = x;
        // 初始时处理特殊情况
        if (ans <= 2) {
            ans++;
            n--;
        }
        // 快速位移操作
        if (n > 0) {
            // 一次移动64位，尽量减少操作次数
            if (n >= 64) {
                ans = (ans << 64) % MOD;
                n -= 64;
            }
            // 最后剩余的位移
            ans = (ans << n) % MOD;
        }
        print(ans);
        cout << '\n';
    }
    return 0;
}
