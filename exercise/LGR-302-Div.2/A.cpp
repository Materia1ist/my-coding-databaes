#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n,ans = 100;
        cin >> n;
        for (int i = 0,x,y; i < n; i++)
        {
            cin >> x >> y;
            x = min(x,50);
            if(ans - x < 100) ans = 100;
            else ans -= x;
            if(ans + y <= 400)ans += y;
            else ans = 400;
        }
        cout << ans << endl;
    }
    
}