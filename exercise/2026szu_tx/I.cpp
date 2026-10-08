#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, ans =0 ;
        cin >> n >> m;
        for (int i = 0,temp; i < n; i++)
        {
            cin >> temp;
            ans += (temp - 1) / m;
            ans += 2;
        }
        cout << ans << endl;
    }
    
}