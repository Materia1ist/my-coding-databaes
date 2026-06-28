#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,n,x,d,y,sum=0;
    cin>>k>>n>>x>>d;
    y=(k/1000)+((k%1000)/100)+((k%100)/10)+(k%10);
    for (int i=0 ; i < n; i++)
    {
        if(x%y==0)
        {
            sum++;
        }
        x+=d;
    }
    cout<<sum;
    return 0;
}