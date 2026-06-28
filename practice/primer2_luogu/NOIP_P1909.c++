//判断方案问题进阶
#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n,w,a1,a2,a3,b1,b2,b3,w1,w2,w3;//n购买数量,w花费,1、2、3为方案，a支装，b元/装
    //!运用到除法尽量主要数据类型，最好用double
    cin>>n>>a1>>b1>>a2>>b2>>a3>>b3;
    //特殊情况
    if(n==0)
    {cout<<0;return 0;}
    //计算各方案花费
    {w1=b1*ceil(n/a1);
    w2=b2*ceil(n/a2);
    w3=b3*ceil(n/a3);}
    //判断并输出最小
    int key=w1;
    {if(w2<key)
    {key=w2;}
    if(w3<key)
    {key=w3;}}
    cout<<key;
    return 0;
}