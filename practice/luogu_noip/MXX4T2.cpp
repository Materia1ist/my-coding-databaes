#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a>> b;
        if (a > 0 && b > 0)
        {
            cout << min(abs(a - b),min(a,b));
        }
        else if (a < 0 && b < 0)
        {
            cout <<  min(abs(a - b),min(-a,-b));
        }
        else
            cout << 0;
        cout << '\n';
    }
}