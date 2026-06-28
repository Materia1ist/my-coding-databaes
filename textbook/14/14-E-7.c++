#include<bits/stdc++.h>
using namespace std;
int main()
{
    int L,K,n,sum,key,key2;
    bool flag=0,f1=0,f2=0;
    cin>>L>>K;
    for (int i = L; i <= K; i++)
    {
        //判断质数
        f1=1;
        for (int j = 2; j < i; j++)
        {
            if(i%j==0)
            f1=0;
        }
        //判断各数位和
        f2=0;sum=0;key2=i;
        while (key2 > 10 )
        {
            key=key2%10;
            key2/=10;
            sum+=key;
        }
        sum+=key2;
        if(sum==10)
        {f2=1;}
        if(f1==1&&f2==1)
        {cout<<i<<" ";
        flag=1;}
    }
    if(flag==0)cout<<"no";
    return 0;
}