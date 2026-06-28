//闰年判断
#include<bits/stdc++.h>
using namespace std;
int main()
    {
    int a;
    cin>>a;
    if(a%400==0 || (a%4==0 && a%100!=0))//所有满足普通闰年和世纪闰年的结果
    {cout<<1;}
    else
    {cout<<0;}
    return 0;
    }