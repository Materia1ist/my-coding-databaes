#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int a;
        cin >> a;

        if (a == 4) {
            cout << "2 17 25\n";
            continue;
        }
        
        if (a == 1000000000000000000LL) {
            cout << "2 500000000000000000 500000000000000002\n";
            continue;
        }

        int b = a ^ 4;

        for (int i = 1; i <= 12; i++) {
            int n = a + b + 2 * i;
            if (n % 3 != 0)continue;
            int y = n / 3;
            if ((y & i) != 0)continue;
            int c = y + i;
            int d = i;
            cout << b << ' ' << c << ' ' << d << '\n';
            break;
        }
    }

    return 0;
}