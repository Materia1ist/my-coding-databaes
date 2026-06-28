#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    scanf("%d",&n);
    int a[n+2];
    for (int i = 1; i <= n; i++)
    {
        scanf("%1d",&a[i]);
    }
    char c[10][5][4]= //打表数组，坑1
{//没有任何技术含量的打表
	"XXX",//0
	"X.X",
	"X.X",
	"X.X",
	"XXX",
	"..X",//1,右对齐，坑2
	"..X",
	"..X",
	"..X",
	"..X",
	"XXX",//2
	"..X",
	"XXX",
	"X..",
	"XXX",
	"XXX",//3
	"..X",
	"XXX",
	"..X",
	"XXX",
	"X.X",//4
	"X.X",
	"XXX",
	"..X",
	"..X",
	"XXX",//5
	"X..",
	"XXX",
	"..X",
	"XXX",
	"XXX",//6
	"X..",
	"XXX",
	"X.X",
	"XXX",
	"XXX",//7
	"..X",
	"..X",
	"..X",
	"..X",
	"XXX",//8
	"X.X",
	"XXX",
	"X.X",
	"XXX",
	"XXX",//9
	"X.X",
	"XXX",
	"..X",
	"XXX"
};
    for (int I = 0; I < 5; I++)//层循环输出
    {
        for (int i = 1; i <= n; i++)//行读结果+循环输出
        {
            printf("%c%c%c",c[a[i]][I][0],c[a[i]][I][1],c[a[i]][I][2]);
            if(i!=n)
            printf(".");
        }
        printf("\n");
    }
    return 0;
}