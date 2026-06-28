#include<bits/stdc++.h>
using namespace std;
int a[10];

void CountNumber (int n)
{
    while(n>10)
    {
        a[n%10]++;
        n/=10;
    }
    a[n]++;
}

void Output ()
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",a[i]);
    }
}

int main ()
{
    int m,n;
    scanf("%d%d",&m,&n);
    memset (a,0,sizeof(a));
    for (int i = m; i <= n; i++)
    {
        CountNumber (i);
    }
    Output ();
}