//最小公因数
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,k;
    double n;
    cin>>a>>b;
    if(a>b)
    {k=a;a=b;b=k;}
    k=a;
    for (int i = 1; k%b!=0 ; i++)
    {
        k=a*i;
    }
    cout<<k;
}