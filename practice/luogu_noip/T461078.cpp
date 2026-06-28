#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a; // 动态数组a

int dfs(int l, int r) {
    if (l >= r) {
        return 0;
    }
    int ans = 0, maxx = 0, cnt = 0;
    vector<int> div; // 动态数组div
    div.push_back(l);
    
    for (int i = l; i <= r; i++) {
        if (a[i] > maxx) {
            maxx = a[i];
            cnt = 0;
        }
        if (a[i] == maxx) {
            div.push_back(i);
            cnt++;
        }
    }
    div.push_back(r); // get div and count max
    if(cnt == 2){
        return 0;
    }
    // half+half-
    if(maxx == 0)
    {
        ans = cnt * (cnt - 1) / 2;
    }
    else{
        int c = cnt / 2, b = cnt - c;
        ans = (c * (c - 1) + b * (b - 1)) / 2;
    }
    

    for (int i = 1; i <= cnt; i++) {
        ans += dfs(div[i - 1] + 1, div[i] - 1);
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    a.resize(n + 1); // 调整大小以适应从 1 到 n 的索引

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 0) a[i] = -a[i];
    }
    
    cout << dfs(1, n);
}
