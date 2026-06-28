#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 5];
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i > 1 && a[i] != a[i - 1])
        {
            flag = 1;
        }
    }
    if (flag)
    {
        cout << n - 1;
    }
    else
    {
        cout << 0;
    }
}