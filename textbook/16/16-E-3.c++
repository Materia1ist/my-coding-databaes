#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum;
    cin>>n;
    int a[n+1],b[n+1];
    for (int i = 1; i <= n; i++)//输入
    {
        cin>>a[i];
    }
    for (int i = 1; i <= n; i++)//判断
    {
        sum=0;
        for (int j = 1; j < i; j++)
        {
            if(a[i]<a[j])sum++;//前面的数比当前数大，自加
        }
        b[i]=sum;
    }
    for (int i = 1; i <= n; i++)//输出
    {
        cout<<b[i]<<" ";
    }
}