#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int x,y,n,a,b;
    cin>>x>>y>>n;
    for (int i = 1; (n>=i)&&(x>y) ; i*=2)
    {
        n-=i;
        x/=2;
    }
    a=x;b=n;
    if(x<y)
    {
        cout<<a<<" "<<b;
    }
    else
    {
        cout<<a<<" "<<0;
    }
    return 0;
}