//判断两种方案的用时，选最优解
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t1,t2;//题数与两种方案时间
    cin>>n;
    t1=5*n;
    t2=11+3*n;//两种方案的权重
    if(t1<t2)
    {printf("Local");}
    else
    {printf("Luogu");}
    return 0;
} 