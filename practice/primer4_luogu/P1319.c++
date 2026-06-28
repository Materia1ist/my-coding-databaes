//数据压缩
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    scanf("%d",&n);
    bool a[n+1][n+1];
    int i=1,x=1,y=1,k;
    while (i<=n*n)
    {
        scanf("%d",&k);
        for (int j = 1; j <= k; j++)//总数与单数计分离
        {
            a[x][y]=0;
            x++;i++;
            if(x>n){x=1;y++;}//换行
        }
        if(i>n*n){break;}
        scanf("%d",&k);
        for (int j = 1; j <= k; j++)
        {
            a[x][y]=1;
            x++;i++;
            if(x>n){x=1;y++;}
        }
    }
    //输出
    for (y = 1; y <= n; y++)
    {
        for (x = 1; x <= n; x++)
        {
            if(a[x][y]==1)
            printf("1");
            if(a[x][y]==0)
            printf("0");
        }
        printf("\n");
    }
    return 0;
    
}