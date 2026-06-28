#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,m;
    scanf("%d%d",&n,&m);
    bool a[n+1];
    memset(a,1,sizeof(a));
    int sum,k=1;
    for (int j = 1; j < n; j++)//循环去除元素，直到只剩一个
    {
        for (int i = k,sum=0; 1 ; i++)
        {
            sum++;
            if(i>n)//循环，i超过n，返回1
            {i=1;}
            if(a[i]==0)//若元素已被删除，跳过
            {sum--;}
            else if(sum==m)//删除元素
            {a[i]=0;
            k=i+1;//记录k，循环从被删除元素下一个开始
            break;}
        }
    }
    for (int i = 1; i <= n; i++)//寻找剩余元素，输出序号
    {
        if(a[i]==1)
        {
            printf("%d",i);
        }
    }
    return 0;//结束
}