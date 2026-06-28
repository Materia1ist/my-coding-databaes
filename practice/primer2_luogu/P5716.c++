//输出这一年的这一月有多少天
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int Y,M,D;//年月日
    cin>>Y>>M;
    //判断30/31天的月
    if(M==4||M==6||M==9||M==11)
    {cout<<30;}
    if(M==1||M==3||M==5||M==7||M==8||M==10||M==12)
    {cout<<31;}
    if(M==2)//判断2月是否闰月
    {
        if((Y%4==0 && Y%100!=0)||Y%400==0)
        {cout<<29;}
        else
        {cout<<28;}
    }
    return 0;
}