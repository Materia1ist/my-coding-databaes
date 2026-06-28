#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,m,s;
    cin >> n >> m >> s;
    vector<ll> a;
    vector<pair<ll,ll>> pr;
    for (int i = 0; i < m; i++)
    {
        ll t;
        cin >> t;
        a.push_back(t);
    }
    
    for (int i = 0; i < m; i++)
    {
        ll l, r;
        cin >> l >> r;
        pr.push_back({l,r});
    }
    
    
}