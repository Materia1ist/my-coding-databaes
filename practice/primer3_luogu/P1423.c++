#include<bits/stdc++.h>
using namespace std;
int main ()
{
    float s,l=2.0,p=0.98,sum=0;
    int i = 0;
    cin>>s;
    for (; sum < s; i++,l*=p)
    {
        sum+=l;
    }
    cout<<i;
}