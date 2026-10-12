#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

    int n, ans = 0;
    cin >> n;
    int a[n + 1], reb[n + 1], bak[n + 1];
    memset(bak, 0, sizeof bak);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1, temp; i <= n; i++)
    {
        cin >> temp;
        reb[temp] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i < reb[a[i]])
            bak[i - reb[a[i]] + n]++;
        else
            bak[i - reb[a[i]]]++;
    }
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, bak[i]);
    }
    cout << ans;
}