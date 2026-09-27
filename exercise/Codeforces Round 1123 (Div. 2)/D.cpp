#include<bits/stdc++.h>
using namespace std;
bool check(int n, vector<pair<int, bool>> &a)
{
    if (n % 2 == 0)
    {
        for (int i = 1; i + 1 <= n; i += 2)
        {
            if (a[i].second == a[i + 1].second) { cout << "NO\n"; return 0; }
        }
    }
    else
    {
        if (a[1].second == 0) { cout << "NO\n"; return 0; }
        for (int i = 2; i + 1 <= n; i += 2)
        {
            if (a[i].second == a[i + 1].second) { cout << "NO\n"; return 0; }
        }
    }
    return 1;
}
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
        vector<pair<int, bool>> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].first;
            a[i].second = i % 2;
        }
        sort(a.begin() + 1, a.end());
        if(check(n,a))cout << "YES\n";
    }
}