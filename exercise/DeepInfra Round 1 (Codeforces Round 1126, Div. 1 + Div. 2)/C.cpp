#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int p = 1;
        while (p <= n)
        {
            p <<= 1;
        }
        cout << 2 * p - 1 << '\n';
        for (int i = 1; i <= 2 * p - 1; i++)
        {
            int x = i & (-i);
            if (x > n)x = p / 2;
            cout << x << ' ';
        }
        cout << '\n';
    }
}