//分段收费问题
#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n,w;//n用电量，w花费
    cin>>n;
    if(n<=150)
    {w=n*0.4463;}
    if(n>150&&n<=400)
    {w=66.945+((n-150)*0.4663);}
    if(n>400)
    {w=183.52+((n-400)*0.5663);}
    cout<<fixed<<setprecision(1)<<w;
    return 0;

}