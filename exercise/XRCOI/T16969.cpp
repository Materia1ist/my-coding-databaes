#include <bits/stdc++.h>
using namespace std;

inline long long read() {
    long long x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * f;
}

inline void write(long long x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

void solve() {
    long long a = read();
    if (a <= 2 || a == 4) {
        putchar('N'); putchar('o'); putchar('\n');
        return;
    }
    putchar('Y'); putchar('e'); putchar('s'); putchar('\n');
    if (a & 1) {
        write((a - 1) / 2 * ((a - 1) / 2));
        putchar(' ');
        write(((a - 1) / 2 + 1) * ((a - 1) / 2));
        putchar('\n');
    } 
    else if (a % 4 == 0) {
        write((a / 4 - 1) * (a / 4 - 1));
        putchar(' ');
        write((a / 4 + 1) * (a / 4 - 1));
        putchar('\n');
    } 
    else {
        write((a - 2) * (a - 2) / 8);
        putchar(' ');
        write((a + 2) * (a - 2) / 8);
        putchar('\n');
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = read();
    while (t--) {
        solve();
    }
    return 0;
}