#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        cout << max(b-a, a+c-b) << endl;

    }
    
}