//求数列中最大值与最小值的差
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,min=1001,max=0;
    scanf("%d",&n);
    int a[n+1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        if(min>a[i])min=a[i];
        if(max<a[i])max=a[i];
    }
    n=max-min;
    printf("%d",n);
    return 0;
}