#include<bits/stdc++.h>
using namespace std;
long long n[26485];
int bignum[11]={1,2,3};
bool found()
{
    bool f1=0,f2=0,f3=0;
    for (int i = 0; i < 11; i++)
    {
        if(bignum[i]==1)f1=1;
        if(bignum[i]==2)f2=2;
        if(bignum[i]==3)f3=3;
    }
    if(f1&&f2&&f3)
    return 1;
    else return 0;
}
int main()
{
    n[1]=357;n[2]=375;n[3]=537;n[4]=573;n[5]=735;n[6]=753;
    for (int i = 7; i <= 26484; i++)
    {
        while (1)
        {
            bignum[0]+=1;
            for (int j = 0; j <= 10; j++)//carry
            {
                if(bignum[j]==4)
                    bignum[j]-=3,bignum[j+1]++;
                //cout<<bignum[j];
            }
            //cout<<endl;
            if(found())//cheak lest a 357
                break;
        }
        //cout<<"a";
        n[i]=0;
        for (int j = 0; j < 11; j++)
        {
            if(bignum[j]==0)break;
            if(bignum[j]==1)n[i]+=3*(pow(10,j));
            if(bignum[j]==2)n[i]+=5*(pow(10,j));
            if(bignum[j]==3)n[i]+=7*(pow(10,j));
        }
    }
    long long q;
    scanf("%lld",&q);
    int ans=upper_bound(n+1,n+26485,q)-n-1;   
    printf("%d",ans);
}