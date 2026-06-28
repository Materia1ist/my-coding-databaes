#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int x;
    cin>>x;
    if((x%3==0)&&(x%12!=0)&&(x%10==7))
    {cout<<"done";}
    else
    cout<<"fail";
    return 0;
}