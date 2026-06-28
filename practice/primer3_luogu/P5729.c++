///去头尾平均数
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    float max=0.0,min=10.0,a,sum=0.0,result;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%f",&a);//输入
        if(a>max)max=a;//更新最值
        if(a<min)min=a;
        sum+=a;//更新各数和
    }
    sum-=(max+min);//去掉最值
    result=sum/(n-2);//平均
    printf("%.2f",result);
    return 0;
}