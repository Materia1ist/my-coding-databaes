//分段问题
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    double x,w=0;
    bool f;
    cin>>x>>f;
    //分三种情况
    if(x<=240)
    w=x*0.4883;
    if(x>240&&x<=400)
    w=117.192+((x-240)*0.5283);
    if(x>400)
    w=201.72+((x-400)*0.7883);
    //判断是否为商业用电
    if(f=1)
    cout<<w;
    else
    {w=w*2;
    cout<<w;}
    return 0;
}