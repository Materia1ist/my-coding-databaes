#include<bits/stdc++.h>
using namespace std;
bool check(int n)
{
    int cnt = 0;
    for(int i = 0; i < 4; i++)
    {
        cnt += (n&1);
        n >>= 1;
    }
    return !(cnt%2);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,q,ans=0;
        cin >> n >> q;
        int a[n+1];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            ans += check(a[i]);
        }
        cout << ans << ' ';
        for (int i = 0; i < q; i++)
        {
            int x,y;
            cin >> x >> y;
            ans -= check(a[x]);
            a[x] = y;
            ans += check(a[x]);
            cout << ans << ' ';
        }
        cout << endl;
        
    }
    
}