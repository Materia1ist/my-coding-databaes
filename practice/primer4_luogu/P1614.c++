#include<bits/stdc++.h>
using namespace std;
int sum=10001;
int a[3002];
//循环输入
void input(int n)
{
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    //printf("input end\n");
}
//建大堆(无用)
void AdjuseDown(int n,int root)
{
    int par=root,chi=par*2;
    while (chi<=n)
    {
        if((chi+1<=n)&&(a[chi]<a[chi+1]))   {chi=chi+1;}
        if(a[par]<a[chi])
        {
            swap(a[par],a[chi]);
            par=chi,chi=par*2;
        }
        else{break;}
    }
    //printf("adjustdown end\n");
}
//堆排序(无用)
void HeapSort(int n)
{
    for (int i = n/2; i >=1 ; i--)
    {
        AdjuseDown(n,i);
    }
    for (int end=n; end >= 1; end--)
    {
        swap(a[1],a[end]);
        AdjuseDown(end-1,1);
    }
    //printf("heapsort end\n");
}
//判断
void judge(int m,int n)
{
    int k=0;
    for (int i = m; i <= n; i++)
    {
        k=0;
        for (int j = i-m+1; j <= i; j++)
        {
            k+=a[j];
        }
        if(k<sum)
        sum=k;
    }
}

int main()
{
    int m,n;
    scanf("%d%d",&n,&m);
    input (n);
    judge(m,n);
    printf("%d ",sum);
    return 0;
}