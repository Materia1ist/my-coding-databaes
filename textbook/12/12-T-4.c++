#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,sum;
    int x[1000];
    cin>>n;
    x[0]=1;x[1]=1;
    sum=2;
    int i = 2;
    while ( sum<n )
    {
        x[i]=x[i-2]+x[i-1];
        sum+=x[i];
        i++;
    }
    cout<<i;
    return 0;
}