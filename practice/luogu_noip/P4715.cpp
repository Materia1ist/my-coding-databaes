#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    pair<int, int> a[n + 2][1 << n + 3];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= 1 << (n); i++)
    {
        scanf("%d", &a[n][i].first);
        a[n][i].second = i;
    }
    // cout<<"end";

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= 1 << (i); j++)
        {
            if (a[i + 1][j * 2] > a[i + 1][j * 2 - 1])
            {
                a[i][j] = a[i + 1][j * 2];
            }
            else
            {
                a[i][j] = a[i + 1][j * 2 - 1];
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= 1 << (n); j++)
    //     {
    //         printf("%d ", a[i][j].first);
    //     }
    //     printf("\n");
    // }
    if (a[1][1].first < a[1][2].first)
    {
        cout<<a[1][1].second;
    }
    else
    {
        cout<<a[1][2].second;
    }
    return 0;
}