#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll inline lcm(ll a, ll b)
{
    return (a / __gcd(a, b)) * b;
}

// ll cntELe(ll len, ll sta, ll l, ll r)
// {
//     return (((r - sta) / len) + 1);
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll b1, b2, a1, a2, l, r;
    cin >> a1 >> b1 >> a2 >> b2 >> l >> r;
    ll sta, len;
   
    if(a1 < a2)
    {
        swap(a1,a2);
        swap(b1,b2);
    } l = max(l, max(b1, b2));
    sta = b1 + ceil((l - b1) * 1.0 / a1) * a1;
    ll end = min(r, lcm(a1, a2) + l);
    for (; sta <= end; sta += a1)
    {
        if (sta >= b2 && (sta - b2) % a2 == 0)
        {
            cout << (((r - sta) / lcm(a1, a2)) + 1);
            return 0;
        }
    }
    cout << 0;
}
