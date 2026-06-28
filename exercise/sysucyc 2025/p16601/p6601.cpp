#include<bits/stdc++.h>
using namespace std;
long long MOD=1e9+7,n,m;
long long fact[105],bak[105];

int Fact()
{
    fact[0]=1;
    for (int i = 1; i <= 100; i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        cout<<fact[i]<<endl;
    }
}

int dp(int q)
{
    
}

int main()
{
    Fact();
    cin>>n>>m;
    int temp;
    for (int i = 0; i < m; i++)
    {
        cin>>temp;
        bak[temp]++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        cout << dp(temp) << ' ';
    }
}