#include<bits/stdc++.h>
using namespace std;

int findMax(int arr[], int size) {
    int maxIndex=0;
    for(int i=1;i<=size;i++)
        if(maxIndex<arr[i])maxIndex=arr[i];
    return maxIndex;  
}

bool checkExtension(int lx, int ly, int x[], int y[]) {
    // 两序列最大值,开头结尾相同，无论如何都会不成立
    if (findMax(x, lx) == findMax(y, ly)) return 0;
    if (x[1]==y[1]) return 0;
    if (x[lx]==y[ly]) return 0;
    // X列最大，以x为桶，对y进行遍历判断操作
    if (findMax(x, lx) > findMax(y, ly)) {
        bool temp[lx + 2]; memset(temp, 0, sizeof(temp));
        int px = 1, py = 1;

        while (1) {
            if (px <= 0) return 0; // 放不进去，回溯爆了
            if (py > ly) break;    // 放完了
           // if (px == lx && py != ly) py++;
            if (x[px] > y[py]) {
                temp[px] = 1; // temp仅保留最大值，用于回溯判断
                px++;                            // 指向下一个桶
            } else {
                px--; py++; // 指回上一个桶，放入下一个数
                if(py>ly) break;//不存在下一个数
                if (x[px] <= y[py]) {
                    while (px) {
                        temp[px] = 0; // 清空不可放入的桶
                        px--;

                        if (x[px] > y[py]) {
                            temp[px] = 1; // temp仅保留最大值，用于回溯判断
                            px++;                            // 指向下一个桶
                            break;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=lx;i++)
            if (temp[i] == 0) return 0; // 没放满
        return 1;
    }
    // Y列最大，以y为桶，对x进行遍历判断操作
    
    if (findMax(x, lx) < findMax(y, ly)) {
        bool temp[ly + 2]; memset(temp, 0, sizeof(temp));
        int py = 1, px = 1;

        while (1) {
            //printf("%d ",py);    //test
            if (py <= 0) return 0; // 放不进去，回溯爆了
            if (px > lx) break;    // 放完了
            //if (py == ly && px != lx) px++;
            if (y[py] > x[px]) {
                temp[py] = 1; // temp仅保留最大值，用于回溯判断
                py++;                            // 指向下一个桶
            } else {
                py--; px++; // 指回上一个桶，放入下一个数
                if(px>lx) break;//不存在下一个数
                if (y[py] <= x[px]) {
                    while (py) {
                        temp[py] = 0; // 清空不可放入的桶
                        py--;

                        if (y[py] > x[px]) {
                            temp[py] = 1; // temp仅保留最大值，用于回溯判断
                            py++;                            // 指向下一个桶
                            break;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=ly;i++)
            if (temp[i] == 0) return 0; // 没放满
        return 1;
    }
}


int main()
{
    //freopen("expand4.in","r",stdin);
    //freopen("ans.out","w",stdout);
    int c,n,m,q;
    scanf("%d%d%d%d",&c,&n,&m,&q);
    int sx[n+5],sy[m+5],x[n+5],y[m+5];
    memset(sx,0,sizeof(sx));memset(sy,0,sizeof(sy));
    for(int i=1;i<=n;i++)
        scanf("%d",&sx[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&sy[i]);
    printf((checkExtension(n,m,sx,sy) ? "1" : "0"));
    for(int i=1;i<=q;i++)
    {
        for(int i=1;i<=n;i++)//修改初始化
            x[i]=sx[i];
        for(int i=1;i<=m;i++)
            y[i]=sy[i];
        int kx,ky,p,v;
        scanf("%d%d",&kx,&ky);
        while(kx){
            scanf("%d%d",&p,&v);
            x[p]=v;
            kx--;
        }
        while(ky){
            scanf("%d%d",&p,&v);
            y[p]=v;
            ky--;
        }
      //  printf(" %d:",i);
        printf((checkExtension(n,m,x,y) ? "1" : "0"));
    }
    return 0;
}