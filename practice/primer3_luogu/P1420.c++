#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,sum=0,ksum=0;
    scanf("%d",&n);
    int a[n+1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i]-a[i-1]==1)ksum++;
        else ksum=1;
        if(ksum>=sum)
        {sum=ksum;}
    }
    printf("%d",sum);
    return 0;
}