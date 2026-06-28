#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,s=0;
    scanf("%d",&n);
    int a[n+1],b[n+1],c[n+1],sum[n+1];
    scanf("%d%d%d",&a[1],&b[1],&c[1]);
    sum[1]=a[1]+b[1]+c[1];
    for (int i = 2; i <= n; i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        sum[i]=a[i]+b[i]+c[i];
        
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <=n ; j++)
        {
            if(abs(a[i]-a[j])<=5 &&
               abs(b[i]-b[j])<=5 &&
               abs(c[i]-c[j])<=5 &&
               abs(sum[i]-sum[j])<=10 
              )
            s++;
        }
    }
    printf("%d",s);
}