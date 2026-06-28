#include<bits/stdc++.h>
using namespace std;
long long a[1005];
int main(){
    a[0]=1,a[1]=1,a[2]=2;
    for(int i=3;i<=1000;i++) a[i] = a[i-1] + a[i-2];
    int m,n;
    cin>>m>>n;
    if(n-m<0) cout<<0;
    else cout<<a[n-m];
    return 0;
}