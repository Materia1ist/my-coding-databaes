#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans;

inline ll read()
{
    ll x = 0;
    char c = getchar();

    while (!isdigit(c))
    {
        c = getchar();
    }

    while (isdigit(c))
    {
        x = x * 10 + c - '0';
        c = getchar();
    }

    return x;
}
int to[105];
int main()
{
    ll n, a, b, c, d;
    n = read();

    for (int i = 0; i < n; ++i)
    {
        to[i] = read();
    }
    a = n - 1, b = 0, c = 1, d = 2;
    int k = n - 1;
    while (k)
    {
        if (to[a] + to[b] >= to[b] + to[c] && to[c] + to[d] >= to[b] + to[c])
        {
            to[b] += to[c];
            k--;
            to[c] = 0;
        }
        ans += to[b];
        if (!k)
        {
            break;
        }
        
        while (!to[++a])
        {
            a %= n;
        }
        while (!to[++b])
        {
            b %= n;
        }
        while (!to[++c])
        {
            c %= n;
        }
        while (!to[++c])
        {
            c %= n;
        }
        if (k && (a==b&&b==c&&c==d))
        {
            while (to[++b])
            {
                b %= n;
            }b++;
        }
        a %= n;
        b %= n;
        c %= n;
        d %= n;
    }

    cout << ans;
}