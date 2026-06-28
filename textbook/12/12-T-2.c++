#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,d=1;
    cin>>x>>y;
    while (x<=y)
    {
        x*=2;
        d++;
    }
    cout<<d;
    return 0;
}