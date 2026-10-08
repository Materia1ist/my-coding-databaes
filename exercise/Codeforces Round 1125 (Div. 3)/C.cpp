#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n,ans = 0;
        cin >> n;
        int a[n+1],sum[n];
        memset(sum,0,sizeof sum);
        map<int,int> bak;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n - 4; i++)
        {
            sum[i] = a[i] + a[i+2] - a[i+4];
            bak[sum[i]]++;
        }
        for (auto [i,v]:bak)
        {
            ans += v*(v-1)/2;
        }
        for (int i = 1; i <= n - 6; i++)
        {
            if(sum[i] == sum[i+2]) ans--;
        }
        for (int i = 1; i <= n - 8; i++)
        {
            if(sum[i] == sum[i+4]) ans--;
        }
        cout << ans << endl;
    }
}