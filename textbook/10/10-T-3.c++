#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,sum;
    cin>>n;
    //层高
    for (int i = 1; i <= n; i++)
    {
        //层面
        for (int j = 1; j <= i ; j++)
        {
            sum+=j;
        }
        
    }
    cout<<sum;
    return 0;
}
