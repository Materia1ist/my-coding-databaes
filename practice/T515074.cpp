#include<bits/stdc++.h>
using namespace std;


map<long long, __int128> a;

void print128(__int128 x) {
    if(x == 0) { 
        cout << '0';
        return;
    }
    if(x < 0) {
        cout << '-';
        x = -x;
    }
    string s;
    while(x) {
        s.push_back(x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

signed main() {
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int opt, x, y;
        cin >> opt;
        if (opt == 1) {
            cin >> x >> y;
            a[x] += y;
        }
        if (opt == 2) {
            cin >> x >> y;
            a[x] -= y;
        }
        if (opt == 3) {
            for (auto& [key, value] : a) {
                value = 1;
            }
        }
        if (opt == 4) {
            cin >> x;
            print128(x);
            cout << endl;
        }
    }
}
