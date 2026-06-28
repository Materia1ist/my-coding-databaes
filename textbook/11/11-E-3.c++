//守形数
//int IsAutomorphic(int x); c语言自带判断守形数的函数
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int a,b,k;
    cin>>a>>b;
    //判断a,b顺序
    if(a>b)
    {k=a;a=b;b=k;}
    //循环判断输出
    for (int i = a; i <=b ; i++)
    {
        //区分个位数和十位数
        if(i<10)
        {
            if(i==(i*i)%10)
            {cout<<i<<" ";}
        }
        else
        {
            if(i==(i*i)%100)
            {cout<<i<<" ";}
        }
    }
    return 0;
}