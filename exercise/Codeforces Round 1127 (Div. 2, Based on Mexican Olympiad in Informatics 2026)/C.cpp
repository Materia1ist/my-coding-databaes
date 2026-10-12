#include <bits/stdc++.h>
using namespace std;
#define int long long

int l, n, r, mid;

bool check()
{
    int sum = 0;
    for (int i = mid; i >= 1; i--)
    {
        sum += mid / i * i;
        if (sum >= n) return 1;
    }
    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        l = 1, r = n;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (check()) r = mid;
            else l = mid + 1;
        }

        cout << l << '\n';
        int left = n, bag = 1;
        for (int i = l; i >= 1 && left; i--)
        {
            int m = l / i;
            while (m-- && left >= i)
            {
                for (int j = 0; j < i; j++) cout << bag << ' ';
                bag++;
                left -= i;
            }
            if (left < i)
            {
                while (left > 0)
                {
                    cout << bag << ' ';
                    left--;
                }
            }
        }
        cout << '\n';
    }
}