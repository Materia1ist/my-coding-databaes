#include <bits/stdc++.h>
using namespace std;

int T, id;

bool inline operate()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n < 4)
    {
        return false;
    }

    if (id == 4 && n >= 4)
    {
        return true;
    }

    sort(a.begin(), a.end());
    int max_val = a[n - 1], min_val = a[0];

    for (int l = 2; l < n - 2; l++)
    {
        for (int r = n - 2; r >= l; r--)
        {
            if (max_val + min_val == a[r] + a[l])
            {
                if (r == l && (a[l] != a[l + 1] || a[l] != a[l - 1]))
                {
                    // Do nothing
                }
                else
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T >> id;

    while (T--)
    {
        if (operate())
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}
