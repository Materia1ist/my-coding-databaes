#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // For faster input/output
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        int up[n + 1] = {0};
        int bit[33] = {0};
        long long ans = 0;

        for (int i = 1; i <= n; ++i) {
            int x,cnt = 0;
            cin >> x;
            if (x == 0) continue;
            
            int logx = log2(x);
            up[i] = logx + 1;
            x -= 1 << logx;
            
            while (x > 0) {
                bit[++cnt] += (x & 1);
                x >>= 1;
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (up[i] == 0) {
                ans += n;
            } else {
                ans += bit[up[i]];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
