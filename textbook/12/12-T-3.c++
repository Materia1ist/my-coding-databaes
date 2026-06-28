#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,sum=0,k;//k暂时存储
    cin>>n;
    while (n>=5)
    {
        k=n%5;
        sum+=n-(k);
        n=(n/5)+k;
    }
    sum+=n;
    cout<<sum;
}