#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1][n+1];//a[层][列]
    memset(a,0,sizeof(a));
    a[1][1]=1;
    //input
    for (int i = 2; i <= n; i++)//层
    {
        for (int j = 1; j <= i; j++)//列
        {
            a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    }
    //output
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}