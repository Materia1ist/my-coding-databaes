#include<bits/stdc++.h>
using namespace std;
//输入，计算差分数组
void Input_Difference(int*a,int*d,int n)
{
    a[0]=0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        d[i]=a[i]-a[i-1];
    }
}
//输入，快速修改差分数组
void Input_EditDiffenent(int*d,int n)
{
    int l,r,x;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d",&l,&r,&x);
        d[l]+=x;d[r+1]-=x;
    }
}
//还原修改后的原数组，计算前缀和
void Edit_Arrow_PrefixSum (int*a,int*d,int*s,int n)
{
    s[0]=0;
    for (int i = 1; i <= n; i++)
    {
        a[i]=a[i-1]+d[i];
        s[i]=s[i-1]+a[i];
    }
}
//输出指定区间内的前缀和
void Output_PrefixSum(int*s)
{
    int l,r,sum;
    scanf("%d%d",&l,&r);
    sum=s[r]-s[l];
    printf("%d",sum);
}
int main()
{
    int n,p;
    scanf("%d%d",&n,&p);
    int a[n+1],d[n+1],s[n+1];
    Input_Difference(a,d,n);
    Input_EditDiffenent(d,p);
    Edit_Arrow_PrefixSum (a,d,s,n);
    Output_PrefixSum(s);
    return 0;
}