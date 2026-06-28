#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> in, invir;
vector<vector<int>> vir;  // 虚点

int topu() {
    queue<int> e, v;
    int ans = 0;

    while (true) {
        bool processed = false;
       
        for (int i = 1; i < invir.size(); i++) {
            if (invir[i] == 0) {
                for (int j : vir[i]) {
                    in[j]--;
                }
                invir[i] = -1;
                v.push(i);
                processed = true;
            }
        } 
        
        for (int i = 0; i < in.size(); i++) {
            if (in[i] == 0) {
                for (int j : graph[i]) {
                    invir[j]--;
                }
                in[i] = -1;
                e.push(i);
                processed = true;
            }
        }

        // 如果本次循环没有处理任何节点，说明拓扑排序已经完成，退出循环
        if (!processed) {
            break;
        }

        ans++;
    }

    return ans;
}

int main() {
    int n, t;
    cin >> n >> t;
    graph.resize(n + 1);
    in.resize(n + 1, 0);
    invir.resize(t + 1, 0);
    vir.resize(t + 1);

    for (int j = 1; j <= t; j++) {
        int q, u, sta, end;
        vector<int> set;
        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> u;
            if (i == 0) sta = u;
            if (i == q - 1) end = u;
            vir[j].push_back(u);
            in[u]++;
            set.push_back(u);
        }

        for (int i = sta, p = 0; i <= end; i++) {
            if (p < set.size() && set[p] == i) {
                p++;
            } else {
                graph[i].push_back(j);
                invir[j]++;
            }
        }
    }

    int result = topu();
    cout << result << endl;

    return 0;
}
