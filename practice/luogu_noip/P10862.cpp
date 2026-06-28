#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, n, x, a, b;
    cin >> T;
    while (T--)
    {
        cin >> n >> x >> a >> b;
        cout << (x * b) + ((n - x) * a) << endl;
    }
}