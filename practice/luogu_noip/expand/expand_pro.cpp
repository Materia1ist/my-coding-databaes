#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int findMax(const int arr[], int size) {
    int maxIndex = 0;
    for (int i = 1; i <= size; i++)
        if (arr[maxIndex] < arr[i]) maxIndex = i;
    return maxIndex;
}

bool processColumns(int max1, int max2, int size1, int size2, const int col1[], const int col2[], vector<bool>& temp) {
    int p1 = size1 - 1, p2 = 0;  // 修正数组下标

    while (1) {
        if (p1 < 0) return false;  // 放不进去，回溯爆了
        if (p2 >= size2) break;   // 放完了

        if (col1[p1] > col2[p2]) {
            temp[p1] = true;
            p1--;
        } else {
            p1--; p2++;
            if (p2 >= size2) break;  // 不存在下一个数

            if (col1[p1] <= col2[p2]) {
                // 回溯清空不可放入的桶
                while (p1 >= 0) {
                    temp[p1] = false;
                    p1--;

                    if (p1 >= 0 && col1[p1] > col2[p2]) {  // 修正回溯条件
                        temp[p1] = true;
                        p1++;
                        break;
                    }
                }
            }
        }
    }

    return true;
}

bool checkExtension(int lx, int ly, const int x[], const int y[]) {
    if (findMax(x, lx) == findMax(y, ly) || x[0] == y[0] || x[lx - 1] == y[ly - 1]) return false;

    if (findMax(x, lx) > findMax(y, ly)) {
        // X 列最大，以 x 为桶，对 y 进行遍历判断操作
        vector<bool> temp(lx + 2, false);
        return processColumns(findMax(x, lx), findMax(y, ly), lx, ly, x, y, temp) && all_of(temp.begin(), temp.end(), [](bool val) { return val; });
    }

    if (findMax(x, lx) < findMax(y, ly)) {
        // Y 列最大，以 y 为桶，对 x 进行遍历判断操作
        vector<bool> temp(ly + 2, false);
        return processColumns(findMax(x, lx), findMax(y, ly), ly, lx, y, x, temp) && all_of(temp.begin(), temp.end(), [](bool val) { return val; });
    }

    return false;
}

int main() {
    freopen("expand4.in", "r", stdin);

    int c, n, m, q;
    scanf("%d%d%d%d", &c, &n, &m, &q);

    vector<int> sx(n), sy(m), x(n), y(m);

    for (int i = 0; i < n; i++)
        scanf("%d", &sx[i]);

    for (int i = 0; i < m; i++)
        scanf("%d", &sy[i]);

    printf((checkExtension(n, m, &sx[0], &sy[0]) ? "1" : "0"));

    for (int i = 0; i < q; i++) {
        for (int i = 0; i < n; i++)
            x[i] = sx[i];

        for (int i = 0; i < m; i++)
            y[i] = sy[i];

        int kx, ky, p, v;
        scanf("%d%d", &kx, &ky);

        while (kx) {
            scanf("%d%d", &p, &v);
            x[p - 1] = v;
            kx--;
        }

        while (ky) {
            scanf("%d%d", &p, &v);
            y[p - 1] = v;
            ky--;
        }

        printf((checkExtension(n, m, &x[0], &y[0]) ? "1" : "0"));
    }

    return 0;
}
