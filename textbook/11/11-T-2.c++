//判断不符合数组序号的数的量
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum;
    cin>>n;
    int a[n];
    //输入
    for(int i=0 ; i<n ; i++)
    {cin>>a[i];}
    //判断
    for(int i=0 ; i<n ; i++)
    {
        if (a[i]!=i+1)
        {
            sum++;
        }    
    }
    cout<<sum;
    return 0;
}