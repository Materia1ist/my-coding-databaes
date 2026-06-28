#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

// 读入数据函数
inline unsigned long long read() {
    unsigned long long s = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        s = s * 10 + c - '0';
        c = getchar();
    }
    return s;
}

int main() {
    unsigned long long n, m;
    n = read();
    m = read();
    
    vector<unsigned long long> a(n);
    for (unsigned long long i = 0; i < n; i++) {
        a[i] = read();
    }
    
    unordered_map<unsigned long long, unsigned long long> product_count;
    
    // 预先计算所有 a_i * a_j 的值及其出现次数
    for (unsigned long long i = 0; i < n; i++) {
        for (unsigned long long j = 0; j < n; j++) {
            unsigned long long product = a[i] * a[j];
            product_count[product]++;
        }
    }
    
    unsigned long long ans = 0;
    
    // 计算结果
    for (const auto& entry : product_count) {
        unsigned long long product = entry.first;
        unsigned long long count = entry.second;
        ans = (ans + count * (m / product) % MOD) % MOD;
    }
    
    printf("%llu\n", ans);
    
    return 0;
}
