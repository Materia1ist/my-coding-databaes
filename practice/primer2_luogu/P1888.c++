//排序加分数化简
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    //由大到小排序
    {
        int key;
        if(a<c)
        {key=c;c=a;a=key;}
        if(a<b)
        {key=b;b=a;a=key;}
        if(b<c)
        {key=c;c=b;b=key;}
    }
    //分数化简
    int n=0;
    if(c==0)
    {cout<<0;
    return 0;}
    if((a%c)==0)
    {n=a/c;
    cout<<1<<"/"<<n;}
    else
    //化简除公因数如：9/24
    while (a>n||c>n)
    {
        n++;
        if((a%n==0)&&(c%n==0))
        {
            a=a/n;
            c=c/n;
        }
    }
    cout<<c<<"/"<<a;
    return 0;
}