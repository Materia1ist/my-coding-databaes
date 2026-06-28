#include <bits/stdc++.h>
#define ll long long
#define MAXN 10000000
using namespace std;

void solve()
{
    int a0,a1,b0,b1,ans = 0,p,q;
    cin >> a0 >> a1 >> b0 >> b1;
    p = a0/a1, q = b1/b0;
    for (int i = 1; i*i <= b1; i++)
    {
        if(b1%i!=0) continue;
        if (i % a1 == 0 && __gcd(i/a1,p) == 1 && __gcd(q,b1/i) == 1)
        {
            ans++;
        }
        int j = b1/i;
        if(i == j) continue;
        if (j % a1 == 0 && __gcd(j/a1,p) == 1 && __gcd(q,b1/j) == 1)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        solve();
    }
    
    return 0;
}
