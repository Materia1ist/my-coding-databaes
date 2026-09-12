#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 998244353;
int n, x;


int main()
{
    cin >> n >> x;
    //init
    int n2[n + 1],a[n + 1];
    n2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        n2[i] = n2[i - 1] * 2 % MOD;
    }
    

    


}
