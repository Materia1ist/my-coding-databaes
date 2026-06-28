#include <bits/stdc++.h>
using namespace std;

void print_int128(__int128 x) {
    if (x == 0) {
        cout << '0';
        return;
    }
    if (x < 0) {
        cout << '-';
        x = -x;
    }

    char buffer[40]; 
    int i = 0;
    while (x > 0) {
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    }
    for (--i; i >= 0; --i) {
        cout << buffer[i];
    }
}

int main() {
    int n, a, b;
    __int128 c[105][105] = {0};
    __int128 ans1 = 0, ans0 = 0;
    
    cin >> n >> a >> b;
    
    for (int i = 0; i <= 100; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    
    for (int i = 0; i <= a; i++) {
        ans0 += c[i + n - 1][n - 1];
    }
    for (int i = 0; i <= b; i++) {
        ans1 += c[i + n - 1][n - 1];
    }
    
    print_int128(ans0 * ans1);
    cout << endl;
    
    return 0;
}
