#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, d;
    cin >> n >> d;
    int a[n + 1], b[n + 1], f[n + 1], h[n + 1], temp[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        h[b[i]] = i;
        temp[i] = f[b[i]];
    }

    int ans = 0, cnt = 0;

    for (int i = 1; i < n; i++)
    {
        if (temp[i] > temp[i + 1])
            cnt++;
    }

    ans = (cnt - 1) * n + temp[n];
    cout << ans << endl;

    d--;
    while (d--)
    {
        int typ, x, y;
        cin >> typ >> x >> y;
        int p[4];
        if (typ == 1)
        {
            int p1 = h[a[x]];
            int p2 = h[a[y]];

            p[0] = p1 - 1;
            p[1] = p1;
            p[2] = p2 - 1;
            p[3] = p2;
        }
        else
        {
            p[0] = x - 1;
            p[1] = x;
            p[2] = y - 1;
            p[3] = y;
        }
        sort(p, p + 4);
        for (int i = 0; i < 4; i++)
        {
            if (p[i] >= 1 && p[i] < n &&
                (i == 0 || p[i] != p[i - 1]))
            {
                if (temp[p[i]] > temp[p[i] + 1])
                    cnt--;
            }
        }

        if (typ == 1)
        {
            swap(a[x], a[y]);
            swap(f[a[x]], f[a[y]]);

            temp[h[a[x]]] = f[a[x]];
            temp[h[a[y]]] = f[a[y]];
        }
        else
        {
            swap(b[x], b[y]);
            swap(h[b[x]], h[b[y]]);
            swap(temp[x], temp[y]);
        }

        for (int i = 0; i < 4; i++)
        {
            if (p[i] >= 1 && p[i] < n &&
                (i == 0 || p[i] != p[i - 1]))
            {
                if (temp[p[i]] > temp[p[i] + 1])
                    cnt++;
            }
        }
        ans = (cnt - 1) * n + f[b[n]];
        cout << ans << endl;
    }
}