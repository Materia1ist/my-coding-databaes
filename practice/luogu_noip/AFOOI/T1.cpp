#include <bits/stdc++.h>
using namespace std;

void fast_input(__int128 &n) {
    n = 0;
    int c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar();
    }
}

void fast_output(__int128 n) {
    if (n == 0) {
        putchar('0');
        return;
    }
    char buf[40];
    int i = 0;
    while (n) {
        buf[i++] = n % 10 + '0';
        n /= 10;
    }
    while (i--) putchar(buf[i]);
}

int main() {

    long long T;
    cin >> T;
    while (T--) {
        __int128 n;
        int ans = 0;
        fast_input(n);
        while (n) {
            if (n % 2) {
                ans++;
            }
            if ((n / 2) % 2) {
                n = (n + 1) / 2; 
            } else {
                n /= 2;
            }
        }
        cout<<ans;
        putchar('\n');
    }
}
