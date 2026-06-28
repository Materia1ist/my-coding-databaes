#include <bits/stdc++.h>
#define ll long long
#define MOD 20070720
using namespace std;
ll a[500005], ans[5000005];
int lena, lenans;

void solve()
{
    // init
    int n, k;
    cin >> n >> k;
    lena = n;
    lenans = 0;
    ll sum = 0;
    memset(a, 0, sizeof(a));
    memset(ans, 0, sizeof(ans));
    for (int i = lena; i; i--)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = lena; i; i--)
    {
        if (a[i] == 0)
        {
            lena--;
        }
        else
        {
            break;
        }
    }

    // an wei jia
    for (int i = 1; i <= lena; i++)
    {
        int t = lena - i + 1; // times
        ll add;
        for (int j = 1; j <= i; j++)
        {
            add = pow(k, j - 1)*t;
            if(add > MOD){
                break;
            }
            sum += a[i] * add;
            sum %= MOD;
        }
    }
    // jing wei
    ans[1] = sum;
    for (int i = 1; i <= 5000000; i++)
    {
        ans[i + 1] += ans[i] / k;
        ans[i] %= k;
        if (ans[i])
            lenans = i;
    }
}
void output()
{
    for (int i = lenans; i; i--)
    {
        printf("%lld ", ans[i]);
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
        output();
        printf("\n");
    }
}