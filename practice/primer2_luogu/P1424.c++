// 小鱼的航程(多层判断)
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    unsigned long long w,d,D,Dall,Wn,Wl,key;//w周几，d过了几天，D有效几天,Wn完全过了几周,Wl最后一周是周几,dall从周一算起的总天数,key暂时存储
    cin>>w>>d;
    //判断第一周的情况
    if(1<=w&&w<=5)
    {Dall=w+d;
    Wn=(Dall/7);//去掉最后一周
    Wl=Dall%7;
        //判断最后一周的情况
        if(0<=Wl&&Wl<=5)
        {D=5*Wn-w+1+Wl;}
        else
        {D=5*Wn-w+1+5;}
    }
    else
    {Dall=w+d;
    Wn=(Dall/7)-1;//去掉最后一周&最开始一周
    Wl=Dall%7;
        //判断最后一周的情况
        if(0<=Wl&&Wl<=5)
        {D=5*Wn+Wl;}
        else
        {D=5*Wn+5;}
    }
    cout<<D*250;
    return 0;
}