#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool check()
{
    int n;
    cin >> n;
    ll a[n], b[n];
    bool opt[n];
    memset (opt,0,sizeof opt);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i <= n-2; i++)
    {
        if((a[i+1] ^ a[i]) == b[i])
        {
            a[i] = a[i+1] ^ a[i];
            opt[i] = 1;
        }
    }
    if(a[n-1]!=b[n-1]) return 0;
    for (int i = n-2; i >= 0; i--)
    {
        if(a[i] != b[i] && opt[i] == 0)
        {
            if((a[i+1] ^ a[i]) != b[i]) return 0;
            a[i] = a[i+1] ^ a[i];
        }
    }

    return 1;
}
int main()
{
   // cout << (5 ^ 1);

    int t;
    cin >> t;
    while (t--)
    {
        if(check())cout << "yes\n";
        else cout << "no\n";
    }
}