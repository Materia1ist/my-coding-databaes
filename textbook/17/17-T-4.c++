#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n-i; j++)//从小到大排序
        {
            if(a[j]>a[j+1])
            {swap(a[j],a[j+1]);}
        }    
    }
    for (int i = 1; i <= n; i+=2)//奇偶数分别输出
    {
        printf("%d ",a[i]);
    }
    if(n%2==0)
    {
        for (int i = n; i >= 2; i-=2)
        {
            printf("%d ",a[i]);
        }
    }
    else
    {
        for (int i = n-1; i >= 2; i-=2)
        {
            printf("%d ",a[i]);
        }
    }
}