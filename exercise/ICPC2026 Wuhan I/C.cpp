#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, s, d, hp;
    cin >> n >> s >> d >> hp;
    for (int i = 1, a, b, k, t; i <= n; i++)
    {
        cin >> a >> k;
        b = 5 - a;
        if (min(3, a) * s >= hp)
        {
            cout << "Yes\n" << i;
            return 0;
        }t = 0;
        for (; t <= 3 && t <= b; t++)
        {
            if (t * d >= k)
                break;
        }
        if (t * d < k)
        {
            cout << "No";
            return 0;
        }
        hp -= min((3 - t), a) * s;
        if (hp <= 0)
        {
            cout << "Yes\n" << i;
            return 0;
        }

    }
    cout << "No";
    return 0;
}