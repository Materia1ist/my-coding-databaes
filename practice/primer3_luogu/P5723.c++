#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,sum1=0,sum2=0;
    bool f;
    cin>>n;
    for (int i = 2; sum2<=n; i++)
    {
        f=1;
        for (int j = 2; j < i; j++)
        {
            if(i%j==0)
            f=0;
        }
        if(f==1)
        {
            sum2+=i;
            if(sum2<=n)
            {cout<<i<<endl;
            sum1++;}
        }
    }
    cout<<sum1<<endl;
    return 0;
}