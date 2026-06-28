#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    scanf("%d",&n);
    int a[n+1][n+1];
    memset(a,0,sizeof(a));

    //输入幻方

    int x,y;//a[x列][y行]储存数据坐标(类第四象限)
    x=n/2+1;y=1;a[x][y]=1;
    for (int K = 2; K <= n*n; K++)
    {
        if((x!=n)&&(y==1))//1.若(K-1)在第一行但不在最后一列,则将K填在最后一行(K-1)所在列的右一列
        {
            x++;y=n;
            a[x][y]=K;
        }
        else if((x==n)&&(y!=1))//若 (K−1) 在最后一列但不在第一行，则将 K 填在第一列，(K−1) 所在行的上一行；
        {
            x=1;y--;
            a[x][y]=K;
        }
        else if((x==n)&&(y==1))//若 (K−1) 在第一行最后一列，则将 K 填在 (K−1) 的正下方
        {
            y++;
            a[x][y]=K;
        }
        else if((x!=n)&&(y!=1))//若 (K−1) 既不在第一行，也不在最后一列，如果 (K−1) 的右上方还未填数，则将 K 填在 (K−1) 的右上方，否则将 K 填在 (K−1) 的正下方。
        {
            if(a[x+1][y-1]==0)
            {
                x++;y--;
                a[x][y]=K;
            }
            else
            {
                y++;
                a[x][y]=K;
            }
        }
    }

    //输出

    int k=1;
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++,k++)
        {
            printf("%d ",a[x][y]);
        }
        printf("\n");
    }

}