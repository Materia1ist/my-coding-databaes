#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,k;
    scanf("%d",&n);
    for (k=1;k<=100;k++)
    {
        for (x=100;x>=1;x--)
        {
            if(n==52*((7*x)+(21*k)))
            {
                printf("%d\n%d",x,k);
                return 0;
            }
        } 
    }
}