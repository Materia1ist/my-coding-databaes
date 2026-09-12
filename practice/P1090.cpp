#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        q.push(temp);
    }
    ll ans = 0;
    while (q.size() > 1)
    {
        ll a = q.top();
        q.pop();
        ll b = q.top();
        q.pop();
        q.push(a + b);
        ans += a + b;
        
    }
    cout << ans << endl;
}