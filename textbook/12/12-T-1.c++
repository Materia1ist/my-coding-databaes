#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,s=0,i=0;
    cin>>n>>x;
    while (s<n)
    {
        s+=x;
        i++;
        x++;
    }
    cout<<i;
    return 0;
}