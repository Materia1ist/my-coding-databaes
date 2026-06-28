#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin >> a;
    a *= 37;
    int p = a%10;
    a/=10;
    while (a)
    {
        if (a%10 != p)
        {
            cout<<"No";
            return 0;
        }
        a/=10;
    }
    cout<<"Yes";
}