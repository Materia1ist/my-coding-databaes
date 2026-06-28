#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum0=0,sum1=0;
    scanf("%d",&n);
    double keya;
    double a1[n+1],a0[n+1];
    bool f;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%lf",&f,&keya);
        if(f==0)
        {sum0++;a0[sum0]=keya;}
        else
        {sum1++;a1[sum1]=keya;}
    }
    //cout<<sum0<<endl<<sum1<<endl;
    for (int i = 1; i <= sum0; i++)
    {
        for (int j = 1; j <= sum0-i; j++)
        {
            if(a0[j]>a0[j+1])
            {
                swap(a0[j],a0[j+1]);
            }
        }
    }
    for (int i = 1; i <= sum1; i++)
    {
        for (int j = 1; j <= sum1-i; j++)
        {
            if(a1[j]<a1[j+1])
            {
                swap(a1[j],a1[j+1]);
            }
        }
    }
    for (int i = 1; i <= sum0; i++)
    {
        printf("%g ",a0[i]);
    }
    for (int i = 1; i <= sum1; i++)
    {
        printf("%g ",a1[i]);
    }
    return 0;
    
}