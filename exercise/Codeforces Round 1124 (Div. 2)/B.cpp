#include <bits/stdc++.h>
using namespace std;
int opt(int x)
{
    int y = 0;
    while(x)
    {
        y += (x%10) * (x%10);
        x/=10;
    }
    return y;
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
        int bak[1001];memset(bak,0,sizeof bak);
        cin >> n;
        for(int i = 0,x; i < n; i++)
        {
            cin >> x;
            for (int step = 0; step < 1000; step++) {
                x = opt(x);
            }
            bak[x]++;
        }
        int ans = 0;
        for (int i = 1; i <= 1000; i++)
        {
            if(bak[i] > 1)ans += bak[i] * (bak[i] - 1) / 2;
        }
        cout << ans << endl;
        
        
    }
}