#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n;
    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            k=i*j;
            cout<<j<<"+"<<i<<"="<<k<<" ";
        }
        cout<<endl;
    }
    return 0;
}