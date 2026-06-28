#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k,sum;
    cin>>n;
    while (n>=10)
    {
        sum=0;
        while (n>=10)
        {
            k=n%10;
            n/=10;
            sum+=k;
        }
        sum+=n;
        n=sum;
    }
    cout<<n;
    return 0;
}