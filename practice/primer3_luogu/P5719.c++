#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    double a[10000],b[10000];
    cin>>n>>k;
    //输入数组
    int akey=0,bkey=0;
    for (int i = 1; i <= n; i++)
    {
        if(i%k==0)
        {
            a[akey]=i;
            akey++;
        }
        else
        {
            b[bkey]=i;
            bkey++;
        }
    }
    //计算结果
    double _a=0,_b=0;
    for (int i = 0; i <= akey; i++)
    {
        _a=_a+a[i];
    }
    for (int i = 0; i <= bkey; i++)
    {
        _b=_b+b[i];
    }
    //取平均值，输出
    _a=_a/akey;
    _b=_b/bkey;
    cout<<fixed<<setprecision(1)<<_a<<' '<<fixed<<setprecision(1)<<_b;
    return 0;
}