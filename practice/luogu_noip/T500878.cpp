#include <bits/stdc++.h>
#define int128 __int128
using namespace std;

void read_int128(int128 &x) {
    string s;
    cin >> s;
    x = 0;
    bool neg = (s[0] == '-');
    for (int i = (neg ? 1 : 0); i < s.size(); i++) {
        x = x * 10 + (s[i] - '0');
    }
    if (neg) x = -x;
}

void print_int128(int128 x) {
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    if (x == 0) {
        cout << '0';
        return;
    }
    string s;
    while (x > 0) {
        s.push_back((x % 10) + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int128 binarySearch(const std::vector<int128>& a, int128 k) {
    int128 l = 0;
    int128 r = a.size() - 1;
    int128 res = -1;

    while (l <= r) {
        int128 mid = l + (r - l) / 2;

        if (a[mid] >= k) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return res;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int128> a(n + 1), s(n + 1, 0), b(n + 1);

    for (int128 i = 1, t; i <= n; i++) {
        read_int128(t);
        a[i] = t;
        b[t] = i;
        s[t] = n - i + 1;
    }

    for (int128 i = 1; i <= n; i++) {
        s[i] += s[i - 1];
    }

    while (q--) {
        int128 t, k;
        read_int128(t);
        k = binarySearch(s, t);
        print_int128(b[k]);
        cout << ' ';
        print_int128(n - s[k] + t);
        cout << endl;
    }

    return 0;
}
