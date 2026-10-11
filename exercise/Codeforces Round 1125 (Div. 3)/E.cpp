//took 30min
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
        int a[n],b[n],l[n],r[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        l[0] = 0;
        for (int i = 1; i < n; i++)
        {
            l[i] = l[i-1] + (a[i-1] == b[i-1] ? 2 : 1) + (a[i] == b[i-1] ? 2 : 1);
        }
        r[n-1] = (a[n-1] == b[n-1] ? 2 : 1);
        for (int i = n-2; i >= 0; i--)
        {
            r[i] = r[i+1] + (a[i+1] == b[i] ? 2 : 1) + (a[i] == b[i+1] ? 2 : 1);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans,l[i]+r[i]);
        }
        cout << ans << endl;
        
    }
}