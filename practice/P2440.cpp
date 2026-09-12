#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k,sum = 0;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll l = 0, r = sum / k,mid,ans = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (mid == 0)
        {
            l = mid + 1;
            continue;
        }
        ll temp = 0;
        for (int i = 0; i < n; i++)
        {
            temp += a[i] / mid;
        }
        if (temp >= k)
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}