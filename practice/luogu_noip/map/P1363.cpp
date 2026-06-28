#include <bits/stdc++.h>
using namespace std;

int dirx[4] = {1, 0, -1, 0}, diry[4] = {0, 1, 0, -1};
char graph[1500][1500];
bool vis[1500][1500];
short s[1500][1500][2];
int n, m;

bool dfs(int x, int y, int stepx, int stepy) {
    if (x >= n || x < 0) {
        x = (x + n) % n;
        stepx++;
    }
    if (y >= m || y < 0) {
        y = (y + m) % m;
        stepy++;
    }
    if (vis[x][y] && (stepx != s[x][y][0] || stepy != s[x][y][1])) {
        return true;
    }
    if (vis[x][y] || graph[x][y] == '#') {
        return false;
    }
    vis[x][y] = true;
    s[x][y][0] = stepx;
    s[x][y][1] = stepy;
    
    for (int i = 0; i < 4; i++) {
        int xnext = x + dirx[i], ynext = y + diry[i];
        if (dfs(xnext, ynext, stepx, stepy)) {
            return true;
        }
    }

    return false;
}

int main() {
    int x, y;
    while (cin >> n >> m) {
        memset(vis, 0, sizeof(vis));
        memset(s, 0, sizeof(s));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> graph[i][j];
                if (graph[i][j] == 'S') {
                    x = i;
                    y = j;
                }
            }
        }

        if (dfs(x, y, 0, 0)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
