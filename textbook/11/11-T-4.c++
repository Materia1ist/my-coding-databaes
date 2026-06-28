#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,sum=0;
    cin>>n;
    int a[n],b[n];
    //输入
    for(int i=0 ; i<n ; i++)
    {
        cin>>a[i];
        cin>>b[i];
    }
    //判断
    for (int i = 1; i < n; i++)
    {
        if(((a[i-1]>b[i-1])&&(a[i]<b[i]))||((a[i-1]<b[i-1])&&(a[i]>b[i])))//超过
        {
            sum++;
        }
    }
    if(a[n-1]>b[n-1])//a先抵达
    {cout<<"peiqi"<<endl<<sum;}
    if(a[n-1]<b[n-1])//b先抵达
    {cout<<"aimili"<<endl<<sum;}
}