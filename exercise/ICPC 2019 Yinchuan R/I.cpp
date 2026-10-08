#include <bits/stdc++.h>
using namespace std;

int get(char a) {
    if (a >= '0' && a <= '9') return a - '0';
    if (a >= 'A' && a <= 'Z') return a - 'A' + 10;
    if (a >= 'a' && a <= 'z') return a - 'a' + 36;
    return -1;
}

char out(int a) {
    if (a >= 0 && a <= 9) return a + '0';
    if (a >= 10 && a <= 35) return a - 10 + 'A';
    return a - 36 + 'a';
}

int main() {
    int x, y;
    string a, b, ans;
    cin >> x >> y >> a;

    for (char &c : a) {
        c = get(c);
    }
    int first = 0;
    while (first < (int)a.size() && a[first] == 0) ++first;
    a.erase(0, first);
    if (a.empty()) {
        cout << "0\n";
        return 0;
    }
    while (!a.empty()) {
        b.clear();
        int rem = 0;

        for (char digit : a) {
            int cur = rem * x + digit;
            int q = cur / y;
            rem = cur % y;

            if (!b.empty() || q != 0)
                b.push_back((char)q);
        }
        ans.push_back(out(rem));
        a.swap(b);
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}