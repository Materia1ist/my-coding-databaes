#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,t1,t2;
    scanf("%d%d%d",&s,&t1,&t2);
    int a1[s+1],a2[s+1];
    for (int i = 1; i <= s; i++)//输入元素至数组
    {
        a1[i]=1+(i-1)*t1;
        a2[i]=1+(i-1)*t2;
    }
    for (int i = 1; i <= s; i++)//删除重合元素
    {
        for (int j = 1; j <= s; j++)
        {
            if(a1[i]==a2[j])
            {
                a2[j]=0;
                break;
            }
        }
        
    }
    int sum=0;//统计剩余元素个数，输出
    for (int i = 1; i <= s; i++)
    {
        if(a1[i]>0)sum++;
        if(a2[i]>0)sum++;
    }
    printf("%d",sum);
    return 0;
}