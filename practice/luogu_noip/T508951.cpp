#include <bits/stdc++.h>
using namespace std;

const int M = 1e9, C = 1e5 + 5;
int n, m, k, s;
int a[25], b[25], c[20000005] , t[20000005];
bool used[25];

void read()
{
    cin >> n >> m >> k >> s;
    mt19937 rand(s);
    for (int i = 1; i <= n; i++)
    {
        a[i] = rand() % M + 1;
        b[i] = rand() % C + 1;
    }
    for (int i = 1; i <= k; i++)
    {
        c[i] = rand() % n + 1;
        if (used[c[i]] == 0)
        {
            t[i] = 0;
            used[c[i]] = 1;
        }
        
        
    }
}

int main()
{
    read();
    cout << solve() << endl;
    return 0;
}
