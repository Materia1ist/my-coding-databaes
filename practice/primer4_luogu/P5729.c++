#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int sum=0,w,l,h,q;
    scanf("%d%d%d",&w,&l,&h);
    bool cube[w+1][l+1][h+1];//大方块体积
    memset (cube,1,sizeof(cube));
    scanf("%d",&q);
    for (int i = 1; i <= q; i++)//去除相应部分
    {
        int x1,x2,y1,y2,z1,z2;
        scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
        for (int x = x1; x <= x2; x++)
        {
            for (int y = y1; y <= y2; y++)
            {
                for (int z = z1; z <= z2; z++)
                {
                    cube[x][y][z]=0;
                }
            }
        }
    }
    for (int x = 1; x <= w; x++)//读出剩余数量
    {
        for (int y = 1; y <= l; y++)
        {
            for (int z = 1; z <= h; z++)
            {
                if(cube[x][y][z]==1)
                sum++;
            }
        }
    }
    printf("%d",sum);
    return 0;
}