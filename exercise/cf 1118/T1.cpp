#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin  >> t;
    while (t--)
    {
        int n,ans = 10e9 + 5;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << __gcd(a[0],a[n-1])<<endl;
    }
    
}