#include<bits/stdc++.h>
using namespace std;
int main ()
{
    float a[3],key;
    cin>>a[0]>>a[1]>>a[2];
    key=a[0];
    for (int i = 0; i < 3; i++)
    {
        if(key>=a[i])
        key=a[i];
    }
    cout<<fixed<<setprecision(1)<<key;
    return 0;
}