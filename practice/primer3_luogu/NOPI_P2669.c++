#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long k,sum=0,sumd=1;
    scanf("%d",&k);
    for (int n = 1;sumd<=k; n++)
    {
        for (int i = 1; i <= n; i++)
        {
            sum+=n;
            sumd++;
            if(sumd>k)break;
        }
    }
    printf("%d",sum);
    return 0;
}