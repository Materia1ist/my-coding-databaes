//桶排序
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum=0,x,k;
    scanf("%d",&n);
    int b[2000];
    memset(b,0,sizeof(b));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&x);
        b[x]++;
    }
    for (int i = 1; sum < 3&&i<2000; i++)
    {
        if(b[i]>0)
        {
            sum++;
            k=i;
        }
    }
    printf("%d",k); 
}