#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long q, n, m;
    cin >> q;
    while (q--)
    {
        cin >> n >> m;
        if (n && m % 2)
        {
            cout << "Yes\n";
        }
        else if(n == 0 && m % 2 == 0)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}