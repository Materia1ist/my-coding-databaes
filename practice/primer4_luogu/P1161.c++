#include<bits/stdc++.h>
using namespace std;

int main ()
{
    bool arr[2000001];
    memset(arr,0,sizeof(arr));
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        double a;
        int t,k;
        scanf("%lf%d",&a,&t);
        for (int j = 1; j <= t ; j++)
        {
            k=j*a;
            if(arr[k]==0)arr[k]=1;
            else arr[k]=0;
        }
    }
    int k;
    for (k=1;; k++)
    {
        if(arr[k]==1)
        break;
    }
    printf("%d",k);
}