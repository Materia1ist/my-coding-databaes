#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i = 1; i < n; i++)//从小到大冒泡排序
    {
        for (int j = 1; j <= n-i; j++)
        {
            if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
        }
    } 
    int k,num;
    scanf("%d",&k);
    for (int i = 1; i <= k; i++)//提取输出
    {
        scanf("%d",&num);
        printf("%d\n",a[num]);
    }
    return 0;
}