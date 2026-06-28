#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;
int main()
{
    int n;
    cin >> n;
    short cnt[MAXN];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        for (int j = 1; j <= sqrt(a); j++)
        {
            if (a % j == 0)
            {
                cnt[j]++;
                if (a / j != j)
                {
                    cnt[a / j]++;
                }
            }
        }
    }
    int p = MAXN - 1;
    for (int i = 1; i <= n; i++)
    {
        while (cnt[p] < i)
        {
            p--;
        }
        cout << p << endl;
    }
}