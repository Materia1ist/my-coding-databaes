#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,k,l=0,r,ans=0,d,p;
        cin >> n >> k;
        r = n - 1;
        int a[n];
        d = n - k + 1;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        p = min(k-1,d);
        k = p;

        while(k--)
        {
            ans += max(a[l],a[r]);
            l++;
            r--;
        }

        if(d > p)
        {
            while(l <= r)
            {
                ans += a[l++];
            }
        }

        cout << ans << endl;
    }
}