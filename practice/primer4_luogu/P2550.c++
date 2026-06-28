#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int N,sum;
    scanf("%d",&N);
    int flag[8],arr[8],prize[8];
    memset(prize,0,sizeof(prize));
    for (int i = 1; i <= 7; i++)//循环输入中奖号码
    {
        scanf("%d",&flag[i]);
    }
    for (int i = 1; i <=N; i++)
    {
        sum=0;//初始化中奖个数
        for (int j = 1; j <= 7; j++)
        {
            scanf("%d",&arr[j]);//循环输入彩票号码
            for (int I = 1; I <= 7; I++)//循环对比
            {
                if(arr[j]==flag[I])
                sum++;
            }
        }
        prize[8-sum]++;
    }
    for (int i = 1; i <= 7; i++)//循环输出
    {
        printf("%d ",prize[i]);
    }
    
}