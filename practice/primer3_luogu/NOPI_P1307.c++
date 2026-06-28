#include<bits/stdc++.h>
using namespace std;

void Invertion (long long*n)
{
    long long New_n=0;
    while (*n>=10)
    {
        New_n+=*n%10;
        New_n*=10;
        *n/=10;
    }
    *n+=New_n; 
}
int main ()
{
    long long n;
    scanf("%lld",&n);
    bool fSign;
    if(n<0) {fSign=0;n=-n;}
    else fSign=1;
    Invertion (&n);
    if(fSign==0) printf("-");
    printf("%lld",n);
}