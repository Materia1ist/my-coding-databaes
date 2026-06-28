#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    bool m[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> m[i][j];
        }
    }
    int sum;
    for (int i = 1; i <= n; i++)
    {
        sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (m[i][j])
                sum++;
        }
        if (sum == n)
        {
            cout << "Yes";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (m[j][i])
                sum++;
        }
        if (sum == n)
        {
            cout << "Yes";
            return 0;
        }
    }
    sum = 0;
    for (int j = 1; j <= n; j++)
    {
        if (m[j][j])
            sum++;
    }
    if (sum == n)
    {
        cout << "Yes";
        return 0;
    }
    sum = 0;
    for (int j = 1; j <= n; j++)
    {
        if (m[j][n - j + 1])
            sum++;
    }
    if (sum == n)
    {
        cout << "Yes";
        return 0;
    }
    cout << "No";
}