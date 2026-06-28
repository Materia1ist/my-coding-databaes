#include <bits/stdc++.h>
using namespace std;

long long get_popcount(long long n) {
    long long cnt = 0;
    while (n > 0) {
        cnt += (n & 1);
        n >>= 1;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N; // 测试数据组数
    cin >> N;
    
    for (long long i = 0; i < N; i++) {
        long long n; 
        cin >> n;
        
        long long cnt1 = 0, cnt2 = 0; 
        
        for (long long j = 0; j < n; j++) {
            long long w; 
            cin >> w;
            if (get_popcount(w) % 2 == 1)  
                cnt1 += w;
            else
                cnt2 += w;
        }
        cout << max(cnt1, cnt2) << "\n";
    }
    return 0;
}