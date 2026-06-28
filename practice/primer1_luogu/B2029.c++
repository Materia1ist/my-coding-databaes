//大象饮水
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int h,r;
    double pi,n,v1,v2;//n为桶数,v1为总量20L,v2为单桶体积
    pi=3.14;
    v1=20000;
    cin>>h>>r;
    v2=h*r*r*pi;
    n=ceil(v1/v2);//向上取整
    cout<<n;
    return 0;
}