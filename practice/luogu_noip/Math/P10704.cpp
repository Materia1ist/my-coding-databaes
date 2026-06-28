#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read()
{
    ll s = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
        s = s * 10 + c - '0', c = getchar();
    return s;
}
inline void print(ll n){
    if(n<0){
        putchar('-');
        n*=-1;
    }
    if(n>9) print(n/10);
    putchar(n % 10 + '0');
}
const ll MOD = 998244353;

ll binarySearch(int key)
{

}

int main()
{
    ll n, m, ans = 0;
    map<ll, ll> a; // 使用map保持有序
    vector<ll> a2;
    n = read();
    m = read();

    for (ll i = 1,t; i <= n; i++)
    {
        t = read();
        a2.push_back(t);
        a[t]++;
    }
    sort(a2.begin(),a2.end());
    



    // for (auto iti = a.begin(); iti != a.end(); iti++)
    // {
    //     for (auto itj = iti; itj != a.end(); itj++)
    //     {
    //         ll product = iti->first * itj->first;
    //         if (product > m)
    //             break;
    //         if (iti == itj)
    //         {
    //             ans += iti->second * itj->second * (m / product);
    //             ans %= MOD;
    //         }
    //         else
    //         {
    //             ans += 2 * iti->second * itj->second * (m / product);
    //             ans %= MOD;
    //         }
    //     }
    // }
    ans %= MOD;
    print(ans);
    return 0;
}