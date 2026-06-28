//未解，需要高精度
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long S=0,key;//S为结果，key为中间存储
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)//n有多少个数
    {
        key=1;
        for (int j = 1; j <=i ; j++)//一个数的阶乘
        {
            key=key*j;
        }
        S=S+key;    
    }
    cout<<S;  
}