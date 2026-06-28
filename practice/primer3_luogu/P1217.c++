#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long L,R;
    int f=0;
    cin>>L>>R;
    if(L%2==0)
    L++;
    for (long long i = L; i <= R; i+=2)
    {
        if((i%10==1)||(i%10==3)||(i%10==7)||(i%10==9)||i==5)
        {f=1;}
        else
        {f=0;}
        if((1000 <= i && i <= 9999) || (100000 <= i && i <= 999999) || (10000000 <= i && i <= 99999999))
        {f=0;}
        if(f==1)
        {
            f=0;
            int k;
            long long a=i,b=0;
            while (a>0)
                {
                    b*=10;
                    b+=a%10;
                    a/=10;
                }
            if(b==i)
            f=1;
        }
        if(f==1)
        {
            {
                f=1;
                for (int j = 2; j <= sqrt(i); j++)
                {
                    if(i%j==0)f=0;
                }
            }
            if(f==1)
            {
                printf("%d\n",i);
            }
        }
    }
    return 0;
}