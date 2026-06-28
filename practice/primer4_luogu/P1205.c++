///喜欢堆模拟wc，拦不住的
#include<bits/stdc++.h>
using namespace std;
//
int x_1,x_2,y_1,y_2,n;//x1,x2,y1,y2,xk,yk储存缓冲
char k;
int arr[11][11];//输入数据arr[x1][y1]
int res[11][11];//计算结果res[x2][y2]
int change[11][11];//要求输出结果change[x2][y2]
int karr[11][11];
bool f1=0,f2=0;
void Text_output_res()
{
    for (int y=1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            printf("%d",res[x][y]);
        }
        printf("\n");
    }
}
void Text_output_input()
{
    for (int y=1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            printf("%d",arr[x][y]);
        }
        printf("\n");
    }
}
void input()
{int x,y;
    for (y = 1; y <= n; y++)
    {
        for (x = 1; x <= n; x++)
        {
            cin>>k;
            if(k=='@'){arr[x][y]=1;}//@
            if(k=='-'){arr[x][y]=0;}//-
        }
    }
    for (y = 1; y <= n; y++)
    {
        for (x = 1; x <= n; x++)
        {
            cin>>k;
            if(k=='@'){change[x][y]=1;}//@
            if(k=='-'){change[x][y]=0;}//-
        }
    }
}

int judge()//判断arr与res是否完全相同
{
    f1=1;
    for (int y=1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            if(change[x][y]!=res[x][y]){f1=0;return 0;}//不相同退出判断，返回f1=0不相同
        }
    }return 0;
}

void way1()//转90°：图案按顺时针转90°。
{
    for (y_1=1,x_2=n; y_1 <= n; y_1++,x_2--)
    {
        for (x_1 = 1,y_2=1; x_1 <= n; x_1++,y_2++)
        {
            res[x_2][y_2]=arr[x_1][y_1];
        }
    }
    judge();
    if(f1==1){f2=1;}
}

void way2()//转180°：图案按顺时针转180°。
{
    for (y_1=1,y_2=n; y_1 <= n; y_1++,y_2--)
    {
        for (x_1 = 1,x_2=n; x_1 <= n; x_1++,x_2--)
        {
            res[x_2][y_2]=arr[x_1][y_1];
        }
    }
    judge();
    if(f1==1){f2=1;}
}

void way3()//转 270 ° ：图案按顺时针转 270 °
{
    for (y_1=1,x_2=1; y_1 <= n; y_1++,x_2++)
    {
        for (x_1 = 1,y_2=n; x_1 <= n; x_1++,y_2--)
        {
            res[x_2][y_2]=arr[x_1][y_1];
        }
    }
    judge();
    if(f1==1){f2=1;}
}

void way4()//反射：图案在水平方向翻转（以中央铅垂线为中心形成原图案的镜像）。
{
    for (y_1=1,y_2=1; y_1 <= n; y_1++,y_2++)
    {
        for (x_1 = 1,x_2=n; x_1 <= n; x_1++,x_2--)
        {
            res[x_2][y_2]=arr[x_1][y_1];
        }
    }
    judge();
    if(f1==1){f2=1;}
}
int way5()//组合：图案在水平方向翻转，然后再按照 1~3之间的一种再次转换。
{
    for (y_1=1,y_2=1; y_1 <= n; y_1++,y_2++)
    {
        for (x_1 = 1,x_2=n; x_1 <= n; x_1++,x_2--)
        {
            res[x_2][y_2]=arr[x_1][y_1];
        }
    }
    for (int y=1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            karr[x][y]=arr[x][y];
            arr[x][y]=res[x][y];
        }
    }
    way1();if(f2==1)return 0;
    way2();if(f2==1)return 0;
    way3();if(f2==1)return 0;
    for (int y=1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            arr[x][y]=karr[x][y];
        }
    }
    return 0;
}
int way6()//不变
{
    f2=1;
    for (int y=1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            if(change[x][y]!=arr[x][y]){f2=0;return 0;}//不相同退出判断，返回f1=0不相同
        }
    }return 0;
}

int main ()
{
    scanf("%d",&n);
    input();
    //Text_output_input();
    way1();if(f2==1){printf("1");return 0;}
    way2();if(f2==1){printf("2");return 0;}
    way3();if(f2==1){printf("3");return 0;}
    way4();if(f2==1){printf("4");return 0;}
    way5();if(f2==1){printf("5");return 0;}
    way6();if(f2==1){printf("6");return 0;}
    printf("7");return 0;
    //Text_output_res();
}
