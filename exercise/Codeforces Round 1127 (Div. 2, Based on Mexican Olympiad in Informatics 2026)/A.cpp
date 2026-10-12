#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n+1];
        for (int i = n; i >= 1; i--)
        {
            cin >> a[i];
        }
        int p = 0;
        for (int i = 1; i <= n; i++)
        {
            p = a[i] * 2 - p;
        }
        cout << p/2 << endl;

        
    }
    
}