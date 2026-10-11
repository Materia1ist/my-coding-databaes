#include <bits/stdc++.h>
using namespace std;
bool check()
{
    int n, k;
    cin >> n >> k;
    vector bak(n+2,0);
    for (int i = 0, temp; i < n; i++)
    {
        cin >> temp;
        bak[temp]++;
    }
    for (auto v : bak)
    {
        if (v >= 2 * k)
            continue;
        if(v == 2 * k - 1)return 1;
        else return 0;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        if(check())cout << "yes\n";
        else cout << "no\n";
    }
}