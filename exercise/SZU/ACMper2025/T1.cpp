#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, g,temp;
    cin >> n;
    cin >> g;
    for (int i = 1; i < n; i++)
    {
        cin >> temp;
        g = __gcd(g,temp);
    }
    //map<ll,ll> bak;
    ll ans = 1;
    for (ll i = 2; i*i <= g; i++)
    {
        ll cnt = 0;
        while(g % i == 0)
        {
            g /= i;
            cnt++;
        }
        ans *= (cnt+1);
    }
    if(g > 1)ans *= 2;
    cout << ans;
}

/*
int main()
{
    ll n, MIN =  LLONG_MAX;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        MIN = min(MIN,a[i]);
    }
    map<ll,ll> bak;
    for (int i = 2; i*i <= MIN; i++)
    {
        while(MIN % i == 0)
        {
            MIN/=i;
            bak[i]++;
        }
    }
    if(MIN > 1)bak[MIN]++;
    for (int i = 0; i < n; i++)
    {
        for (const auto& [key, value] : bak) 
        {
            if(a[i]%key)
            {
                bak.erase(key);
                break;
            }
            ll temp = 0;
            while (a[i]%key == 0)
            {
                a[i] /= key;
                temp++;
            }
            bak[key] = min(temp,bak[key]);
        }
    }
    ll ans = 1;
    for (const auto& [key, value] : bak) 
    {
        ans *= (value+1);
    }
    cout << ans;
}*/