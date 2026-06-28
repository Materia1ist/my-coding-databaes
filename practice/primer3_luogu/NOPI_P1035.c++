#include<bits/stdc++.h>
using namespace std;
int main ()
{
    double s=0,n;
    int k;
    scanf("%d",&k);
    for (n = 0; s<=k ; n++)
    {
        
        s+=1/n;
    }
    cout<<n;
    return 0;
}