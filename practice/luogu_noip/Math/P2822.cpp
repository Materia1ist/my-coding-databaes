#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2003;
ll a[MAXN];
int sum[MAXN][MAXN];
int main()
{
    int t,k;
    cin>>t>>k;
    a[0] = 1;
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = i; j > 0; j--)
        {
            a[j] += a[j-1];
            a[j] %= k;
            if (a[j]%k == 0)
            {
                sum[i][j] = 1;
            }
        }
        
        if(k == 1)sum[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            sum[i][j] += sum[i][j-1];
        }
        
    }
    while (t--)
    {
        int n,m;
        ll ans = 0;
        cin>>n>>m;
        for (int i = 0; i <= n; i++)
        {
            ans += sum[i][min(i,m)];
        }
        cout<<ans<<endl;
    }
    
}