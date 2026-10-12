#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        int ans = 0,cnt0 = 0,cnt1 = 0,temp = n;
        vector <bool> b;
        while (temp > 0)
        {
            b.push_back(temp % 2);
            if(temp%2==0) cnt0++;
            else cnt1++;
            temp/=2;
        }
        if(cnt0 < k) ans = k + cnt1 - 1;
        else
        {
            vector<int> sum;
            
        }
        cout << ans << endl;
    }
    
}