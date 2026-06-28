#include<bits/stdc++.h>
using namespace std;
int main()
{
    for (int I = 1; I <= 500; I++)
    {
        int n;
        scanf("%d",&n);
        int a[n+1],ans[n];//a源输入数据，ans差的绝对值
        for (int i = 1; i <= n; i++)//循环输入
        {
            scanf("%d",&a[i]);
        }
        for (int i = 1; i < n; i++)//计算结果，录入
        {
            ans[i]=abs(a[i]-a[i+1]);
        }
        bool f;
        for (int i = 1; i < n; i++)//判断是否符合条件
        {
            f=0;
            for (int j = 1; j < n; j++)//判断数是否在1~n-1范围内
            {
                if(ans[i]==j)
                {
                    f=1;
                    break;
                }
            }
            for (int j = 1; i < n; i++)//判断数是否有重合
            {
                if(i!=j&&ans[i]==ans[j])
                {
                    f=0;
                    break;
                }
            }
            if(f==0)
            {
                printf("NO\n");
                break;
            }
        }
        if(f==1)
        {
            printf("YES\n");
        }
    }
    return 0;
}