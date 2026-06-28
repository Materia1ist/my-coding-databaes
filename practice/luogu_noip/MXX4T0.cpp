#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << "YES";
        return 0;
    }

    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    if (ans % (n + 1))
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
}