//低配指针
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a1,b1,c1,a2,b2,c2,a3,b3,c3,a4,b4,c4,a5,b5,c5,a6,b6,c6,a7,b7,c7;//a早上，b下午，c为总数；1~7为星期
    cin>>a1>>b1>>a2>>b2>>a3>>b3>>a4>>b4>>a5>>b5>>a6>>b6>>a7>>b7;
    //运算总时间
    {
        c1=a1+b1;c2=a2+b2;c3=a3+b3;c4=a4+b4;c5=a5+b5;c6=a6+b6;c7=a7+b7;
    }
    //提取最不开心的一天（倒序，key相同取前面那天）
    int key,Dkey;
    key=c7;Dkey=7;
    if(c6>=key){key=c6;Dkey=6;}
    if(c5>=key){key=c5;Dkey=5;}
    if(c4>=key){key=c4;Dkey=4;}
    if(c3>=key){key=c3;Dkey=3;}
    if(c2>=key){key=c2;Dkey=2;}
    if(c1>=key){key=c1;Dkey=1;}
    //判断是否符合标准
    if(key>8)
    {cout<<Dkey;}
    else
    {cout<<"0";}
    return 0;
}