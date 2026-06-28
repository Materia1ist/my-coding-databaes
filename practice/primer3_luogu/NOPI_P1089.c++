#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int DepositMoney,Cash,Expenditure;//deposit money存款，cash现金（手上的），Expenditure支出
    for (int i = 1; i <= 12; i++)
    {
        Cash+=300;
        scanf("%d",&Expenditure);
        Cash-=Expenditure;//扣除支出

        if(Cash<0)//若现金不足以支付开支，输出-X（月份
        {printf("-%d",i);return 0;}

        while (Cash>=100)//存多余的钱
        {
            Cash-=100;
            DepositMoney+=100;
        }  
    }
    Cash+=1.2*DepositMoney;
    printf("%d",Cash);
    return 0;
}