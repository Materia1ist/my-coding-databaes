#include<bits/stdc++.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n+1];
    for (int i = 1; i <= n; i++)//输入数组
    {
        scanf("%d",&a[i]);
    }
 //   printf("1end");
    int opt,x,sum;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d",&opt,&x);
        if (opt==1)
        {
            for (int j = 1; j <= n; i++)//情况一，删除元素
            {
                if(a[j]==x)
                {a[j]=0;break;}
            }
            //printf("2-1end");
        }
        else
        {
            sum=0;
            for (int j = 1; j <= n; j++)//情况二，累计计算元素个数
            {
                if(a[j]==x)
                sum++;
            }
            printf("%d\n",sum);
            //printf("2-2end");
        }
    }
   // printf("2end");
    return 0;
}