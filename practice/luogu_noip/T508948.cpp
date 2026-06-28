#include <bits/stdc++.h>
using namespace std;

void print_int128(__int128 x)
{
    if (x == 0)
    {
        cout << '0';
        return;
    }
    if (x < 0)
    {
        cout << '-';
        x = -x;
    }
    string s;
    while (x > 0)
    {
        s += (x % 10) + '0';
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main()
{
    int n, k;
    cin >> n >> k;
    n = 200000;k = 200000;
    bool a[2000005];
    for (int i = 1; i <= n; i++)
    {
        //cin >> a[i];
        a[i] = i % 2;
    }
    a[n + 1] = 0;

    unsigned long long ans = k * n;

    for (unsigned long long i = 1; i <= n; i++)
    {
        if (a[i] != a[i + 1])
        {
            ans += (i <= k ? i : k);
        }
    }
    cout << ans;
    //print_int128(ans);
}
