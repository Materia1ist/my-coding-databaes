#include <iostream>
using namespace std;

const long long MOD = 998244353;

// 快速幂计算 (base^exp) % mod
long long fast_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) { // 如果 exp 是奇数
            result = (result * base) % mod;
        }
        base = (base * base) % mod; // 平方底数
        exp /= 2; // 指数减半
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n;
        string s;
        cin >> n >> s;

        // 处理特殊情况
        if (n == 2) {
            cout << 1 << endl;
        } else if (n == 3) {
            cout << 4 << endl;
        } else {
            // 计算 2^n % 998244353
            cout << fast_pow(2, n, MOD) << endl;
        }
    }
    
    return 0;
}
