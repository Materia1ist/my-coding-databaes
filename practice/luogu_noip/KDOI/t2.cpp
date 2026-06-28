#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << a[m] << endl;
}
