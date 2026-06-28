#include<bits/stdc++.h>
using namespace std;



int main ()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    bool a[101][101];//a[x][y]第一象限
    memset(a,1,sizeof(a));//初始全黑，黑1亮0
    for (int i = 1; i <= m; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        {
            for (int i = x-2; i <= x+2; i++)
            {
                if(i>0)
                a[i][y]=0;
            }
            for (int i = y-2; i <= y+2; i++)
            {
                if(i>0)
                a[x][i]=0;
            }
            if(x+1>0&&y+1>0)a[x+1][y+1]=0;
            if(x-1>0&&y+1>0)a[x-1][y+1]=0;
            if(x+1>0&&y-1>0)a[x+1][y-1]=0;
            if(x-1>0&&y-1>0)a[x-1][y-1]=0;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        for (int i = x-2; i <= x+2; i++)
        {
            for (int j = y-2; j <= y+2; j++)
            {
                if(i>0&&j>0)
                a[i][j]=0;
            }
        }

    }
    //统计
    int sum=0;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            if(a[x][y]==1)
            sum++;
        }
    }
    printf("%d",sum);
    return 0;
}