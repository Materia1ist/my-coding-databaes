#include<bits/stdc++.h>
using namespace std;

void JudgePrime(int n,bool *f)
{
    *f=1;
    for (int i = 2; i < sqrt(n); i++)
    {
        if(n%i==0)*f=0;
    }
}
int main ()
{
    int n,k;
    bool f=0;
    scanf("%d",&n);
    for (int i = 2; i < sqrt(n); i++)
    {
        if(n%i==0)JudgePrime(i,&f);
        if(f==1){k=n/i;JudgePrime(k,&f);}
        if(f==1){printf("%d",k);break;}
    }
    return 0;
}