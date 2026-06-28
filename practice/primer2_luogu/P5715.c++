//冒泡排序简易
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,key;//key为中间存储
    cin>>a>>b>>c;
    if(a>c)
    {key=a;
    a=c;
    c=key;}
    if(b>c)
    {key=b;
    b=c;
    c=key;}
    if(a>b)
    {key=a;
    a=b;
    b=key;}
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}