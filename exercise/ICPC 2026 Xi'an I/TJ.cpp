#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n],d[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a,a+n);
        for (int i = 0; i < n - 1; i++)
        {
            d[i] = a[i] + a[i + 1]; 
        }
        int ans = 0,R,L,l = 0;
        for (int r = 2; r < n; r++)
        {
            if(r - l < 2) continue;
            while (r - l >= 2 && d[l] <= a[r])
            {
                l++;
            }
            if(r - l >= 2 && r - l + 1 > ans)
            {
                ans = r - l + 1;
                R = r;
                L = l;
            }
 
        }

        if(ans > 0)
        {
            cout << ans << ' ';
            for(;L <= R;L++)
            {
                cout << a[L] << ' ';
            }
            cout << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

}