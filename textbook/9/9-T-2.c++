#include<bits/stdc++.h>
using namespace std;
int main ()
{
    float a[3],keya,keyi;
    cin>>a[0]>>a[1]>>a[2];
    keya=a[0];
    for ( int i = 0 ; i < 3 ; i++)
    {
        if(keya>=a[i])
        {keya=a[i];
        keyi=i+1;}
    }
    cout<<keyi<<" "<<keya;
    return 0;
}