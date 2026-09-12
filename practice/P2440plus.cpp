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
        double temp;
        cin >> temp;
        a[i] = (ll)(temp * 100);
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
    int ans1 = ans / 100;
    int ans2 = ans % 100;
    cout << ans1 << "." << (ans2 < 10 ? "0" : "") << ans2 << endl;
}