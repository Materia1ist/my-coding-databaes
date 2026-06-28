#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum,k,ki;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        k=1;
        if(i%7!=0)
        {
            k=0;
            ki=i;
            while (ki>=10)
            {
                if(ki%10==7)
                {k=1;break;}
                ki/=10;
            }
        }
        if(k==0)sum++;
    }
    cout<<sum;
    return 0;
}