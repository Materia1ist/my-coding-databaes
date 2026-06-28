#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a = 0,b = 0;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if (t)
        {
            b++;
        }
        a = max(a,t);
    }
    cout << a + b;
}