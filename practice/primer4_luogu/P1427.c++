#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int a[101],n=0;
    for (int i = 1; ; i++,n++)
    {
        scanf("%d",&a[i]);
        if(a[i]==0)break;
    }
    for (int i = n; i >= 1; i--)
    {
        printf("%d ",a[i]);
    }
    return 0;
}