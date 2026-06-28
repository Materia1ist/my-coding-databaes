#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long n,sum=0;
    cin>>n;
    bool a[n+1];
    memset(a,true,sizeof(a));
    a[1]=false;a[0]=false;
    for (int i =2; i < sqrt(n); i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if(j%i==0)a[j]=false;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if(a[i]==true)sum++;
    }
    cout<<sum;
    return 0;
}