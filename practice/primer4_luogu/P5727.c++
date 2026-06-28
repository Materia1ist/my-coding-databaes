#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,key=1;
    int a[100000];
    scanf("%d",&n);
    for (int i = 1 ; n>1 ; i++)
    {
        a[i]=n;
        if(n%2==0)
        {n=n/2;}
        else 
        {n=(n*3)+1;}
        key++;
    }
    a[key]=1;
    for (int i = key; i >=1 ; i--)
    {
        printf ("%d ",a[i]);
    }
    return 0;
}