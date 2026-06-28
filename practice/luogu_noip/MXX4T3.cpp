#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if (a == c && b == d)
        {
            cout << 0 << '\n';
        }else
        if(a*b == c*d)
        {
            if (a < c)
            {
                cout << 1 << endl;
                cout << 1 << ' ' << c/a;
            }
            else
            {
                cout << 1 << endl;
                cout << 2  << ' ' << a/c;
            }
            cout << '\n';
        }
        else cout << -1;
    }
    
}