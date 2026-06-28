#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,sum=0;
    cin>>t;
    int end[t+1];
    for (int i = 1; i <= t; i++)
    {
        cin>>n;
        bool a[n+1];
        sum=0;
        memset(a,1,sizeof(a));
        a[0]=0;
        for (int j = 2; j <= n; j++)
        {
            for (int I = 1; I <= n; I++)
            {
                if(I%j==0)
                {
                    if(a[I]==0)
                    {a[I]=1;}
                    else
                    {a[I]=0;}
                }
            }    
        }
        for (int j = 1; j <= n; j++)
        {
            if(a[j]==1)
            {sum++;}
        }
        end[i]=sum;
    }
    for (int i = 1; i <= t; i++)
    {
        cout<<end[i]<<endl;
    }
    return 0;
}