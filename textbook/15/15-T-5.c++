#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,k;
    long long m,min;
    cin>>n;
    bool f=0;
    long long a[n+1];
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    cin>>m;
    for (int i = 1; i <= n; i++)
    {
        min=100000;
        int k1=1;
        while (k1 <= n)
        {
            if(a[k1]<min)
            min=a[k1];
            k1++;
        }
        for (int j = 1; j <= n; j++)
        {
            if(min+a[j]==m)
            {
                if(min>a[j])
                {k=min;min=a[j];a[j]=k;}    
                cout<<min<<" "<<a[j];          
                f=1;
                break;
            }  
        }
        if(f==1)break;
        else{a[k1]=1000000000;}
    }
    if(f==0)cout<<"NO";
    return 0; 
}