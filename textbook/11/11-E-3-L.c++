//完美数
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,sum=0;
    cin>>n;
    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if(i%j==0)
            sum+=j;
        }
        if(sum==i)
        {
            cout<<i<<" ";
        }
        sum=0;
    }
    return 0;
       
}