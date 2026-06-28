//数的性质
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num,_1,_2,a=0,b=0,c=0,d=0;
    cin>>num;
    //判断数是否符合两个性质
    if(num%2==0)
    {_1=1;}
    else
    {_1=0;}
    if(num<=12 && num>4)
    {_2=1;}
    else
    {_2=0;}
    //判断数是否符合各人喜好
    if(_1==1 && _2==1)
    {a=1;}
    if(_1==1 || _2==1)
    {b=1;}
    if((_1==0 && _2==1)||(_1==1 && _2==0))
    {c=1;}
    if(_1==0 && _2==0)
    {d=1;}
    cout<<a<<" "<<b<<" "<<c<<" "<<d;
    return 0;
}
