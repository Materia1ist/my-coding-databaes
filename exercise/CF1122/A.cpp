#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a,b,c,d,MIN = 0x3f3f3f3f;
        cin >> a >> b >> c >> d;
        MIN = min(MIN, b);MIN = min(MIN, c);MIN = min(MIN, d);
        cout << (a-MIN) << endl;
    }
    
}