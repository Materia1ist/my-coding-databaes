#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, p;
    cin >> n >> p;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a > 0)
        {
            p += a;
        }
    }
    cout << p;
}