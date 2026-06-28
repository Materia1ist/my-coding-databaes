#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> f(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < x; ++j) {
            int k;
            cin >> k;
            f[i].push_back(k - 1);
        }
    }
    
    vector<int> result(n, 0);
    for (int i = 0; i < n; ++i) {
        set<int> s;
        for (int j : f[i]) {
            s.insert(j);
            for (int k : f[j]) {
                if (k != i) s.insert(k);
            }
        }
        result[i] = s.size();
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    return 0;
}
