#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool checkExtension(const vector<int>& X, const vector<int>& Y) {
    // 首先，检查 X 和 Y 的长度是否相等
    if (X.size() != Y.size()) {
        return false;
    }

    int n = X.size();

    // 检查 F 和 G 中的元素是否互不相等
    unordered_set<int> fSet(X.begin(), X.end());
    unordered_set<int> gSet(Y.begin(), Y.end());

    if (fSet.size() != n || gSet.size() != n) {
        return false;  // F 或 G 中存在重复的元素，不符合条件
    }

    // 检查是否对于任意 i 都有 f[i] > g[i] 或 f[i] < g[i]
    bool increasing = all_of(X.begin(), X.end(), [&Y](int xi) {
        return any_of(Y.begin(), Y.end(), [xi](int yj) {
            return xi > yj;
        });
    });

    bool decreasing = all_of(X.begin(), X.end(), [&Y](int xi) {
        return any_of(Y.begin(), Y.end(), [xi](int yj) {
            return xi < yj;
        });
    });

    return increasing || decreasing;  // 满足条件
}

int main() {
    int c, n, m, q;
    cin >> c >> n >> m >> q;

    vector<int> X(n);
    vector<int> Y(m);

    for (int i = 0; i < n; ++i) {
        cin >> X[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> Y[i];
    }

    // 初始检查
    cout << (checkExtension(X, Y) ? "1 " : "0 ");

    // 处理额外的查询
    for (int query = 0; query < q; ++query) {
        int kx, ky;
        cin >> kx >> ky;

        // 对 X 进行修改
        for (int i = 0; i < kx; ++i) {
            int px, vx;
            cin >> px >> vx;
            X[px - 1] = vx; // 调整索引为从 0 开始
        }

        // 对 Y 进行修改
        for (int i = 0; i < ky; ++i) {
            int py, vy;
            cin >> py >> vy;
            Y[py - 1] = vy; // 调整索引为从 0 开始
        }

        // 检查是否存在满足条件的序列 F 和 G
        cout << (checkExtension(X, Y) ? "1 " : "0 ");
    }

    return 0;
}
