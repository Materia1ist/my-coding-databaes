//小鱼的游泳时间
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d;
    e=c-a;//小时数
    if(b<=d)
    {
        f=d-b;
    }
    else//前一个时间的min大于后一个，小时中拆60min补
    {
        f=60-b+d;
        e=e-1;
    }
    cout<<e<<' '<<f;
    return 0;
}