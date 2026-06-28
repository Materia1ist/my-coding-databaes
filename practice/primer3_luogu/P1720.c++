#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    scanf("%d",&n);
    long long s[n+1];
    s[0]=0;s[1]=1;
    for (int i = 2; i <= n; i++)
    {
        s[i]=s[i-1]+s[i-2];
    }
    printf("%ld.00",s[n]);
}