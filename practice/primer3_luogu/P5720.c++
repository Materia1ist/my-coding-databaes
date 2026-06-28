#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a;
    cin>>a;
    int d=1;//把第一天也记进去
    while (a>1)
    {
        a=floor(a/2);//向下取整
        d++;
    } 
    cout<<d;
    return 0;
}