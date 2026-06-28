#include<bits/stdc++.h>
using namespace std;
int main()
{

    long long n,m;
    cin>>n;
    while(n)
    {
        cin>>m;
        if(m%3==1){
            printf("Yes");
        }
        else{
            printf("No");
        }
        n--;
    }
    
}