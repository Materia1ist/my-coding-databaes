#include <bits/stdc++.h>
using namespace std;
#define ll long long

queue<long long> q1,q2;
ll bak[1000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        bak[temp]++;
    }
    for (int i = 0; i < 1000005; i++)
    {
        while (bak[i] > 0)
        {
            bak[i]--;
            q1.push(i);
        }
    }
    ll ans = 0;
    while (q1.size() + q2.size() > 1)
    {
        ll a ,b;
        if (q1.size() > 0 && q2.size() > 0)
        {
            if (q1.front() < q2.front())
            {
                a = q1.front();
                q1.pop();
            }
            else
            {
                a = q2.front();
                q2.pop();
            }
        }
        else if (q1.size() > 0)
        {
            a = q1.front();
            q1.pop();
        }
        else
        {
            a = q2.front();
            q2.pop();
        }
        if (q1.size() > 0 && q2.size() > 0)
        {
            if (q1.front() < q2.front())
            {
                b = q1.front();
                q1.pop();
            }
            else
            {
                b = q2.front();
                q2.pop();
            }
        }
        else if (q1.size() > 0)
        {
            b = q1.front();
            q1.pop();
        }
        else
        {
            b = q2.front();
            q2.pop();
        }
        q2.push(a + b);
        ans += a + b;
    }
    cout << ans << endl;
    
}