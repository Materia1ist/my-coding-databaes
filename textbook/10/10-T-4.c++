//1+12+123+...+123...n
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,sum;//1为总结果，2分结果
    cin>>n;
    for (int I = 1; I <=n ; I++)
    {
        for (int i=I,j = 1; 1 <= i; i--,j*=10)
        {
            sum+=i*j;
        } 
    }
    cout<<sum;
    return 0;
}