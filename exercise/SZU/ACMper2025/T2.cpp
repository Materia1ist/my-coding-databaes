///took 58min

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int n, d,ans = 0;
    cin >> n >> d;

    int a[n + 3],b[n+3];
    set<int> bak;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        bak.insert(a[i]);
        bak.insert(a[i]-d);
    }

    for (auto l : bak)
    {
        int r = l + d,temp = 0;
        for (int i = 0; i < n; i++)
        {
            if(a[i] < l)
            {
                b[i] = l;
            }
            else if(a[i] > r)
            {
                b[i] = r;
            }
            else
            {
                b[i] = a[i];
            }
        }
        
        for (int i = 1; i < n; i++)
        {
            temp += abs(b[i] - b[i-1]);
        }
        ans = max(temp,ans);
    }
    cout << ans;



    return 0;
}