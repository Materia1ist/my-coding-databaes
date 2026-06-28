#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    scanf("%d",&n);
    int a[n+1][n+1];//a[x][y] 
    int i=1,x=1,y=1,k1=n,k2=n,k3=1,k4=2;//右下左上边界值
    //input array
    while(i < n*n)
    {
        //向右
        for(;x < k1&&i <= n*n;i++,x++)
        { a[x][y]=i;}
        k1--;
        //向下
        for(;y < k2&&i <= n*n;i++,y++)
        { a[x][y]=i;}
        k2--;
        //向左
        for(;x>k3&&i <= n*n;i++,x--)
        { a[x][y]=i;}
        k3++;
        //向上
        for(;y>k4&&i <= n*n;i++,y--)
        { a[x][y]=i;}
        k4++;
    }
    a[x][y]=i;
    //output array
    for (int y1 = 1; y1 <=n ; y1++)
    {
        for (int x1 = 1; x1 <=n ; x1++)
        {
            printf("%3d",a[x1][y1]);
        }
        printf("\n");
    }
    return 0;
}