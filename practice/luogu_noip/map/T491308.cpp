#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a;
    vector<int> opt;
    int n, r, m = 0, cnt1 = 0, cnt0 = 0;
    cin >> n >> r;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i])
        {
            cnt1++;
        }
        else
        {
            cnt0++;
        }
    }
    if (cnt1 == n || cnt0 == n)
    {
        cout << 0;
        return 0;
    }
    if (cnt1 > cnt0) // all 0->1
    {
        int l, r;
        for (int i = 1; i < n / 2; i++)
        {
            if (a[i] == 0)
            {
                l = i;
                for (int j = l + 1; j <= n; j++)
                {
                    if (a[j] == 1)
                    {
                        r = j - 1;
                        break;
                    }
                }
                for (int j = l - 1; j; j--)
                {
                    opt.push_back(j);
                }
                for (int j = r; j; j--)
                {
                    opt.push_back(j);
                }
                for (; l <= r; l++)
                {
                    a[l] = 1;
                }

                i = r;
            }
        }
        for (int i = n; i >= n / 2; i--)
        {
            if (a[i] == 0)
            {
                r = i;
                for (int j = r - 1; j; j--)
                {
                    if (a[j] == 1)
                    {
                        l = j + 1;
                        break;
                    }
                }
                for (int j = r + 1; j <= n; j++)
                {
                    opt.push_back(j);
                }
                for (int j = l; j <= n; j++)
                {
                    opt.push_back(j);
                }
                i = l;
                for (; l <= r; l++)
                {
                    a[l] = 1;
                }
            }
        }
    }
    else // all 1->0
    {
        int l, r;
        for (int i = 1; i < n / 2; i++)
        {
            if (a[i] == 1)
            {
                l = i;
                for (int j = l + 1; j <= n; j++)
                {
                    if (a[j] == 0)
                    {
                        r = j - 1;
                        break;
                    }
                }
                for (int j = l - 1; j; j--)
                {
                    opt.push_back(j);
                }
                for (int j = r; j; j--)
                {
                    opt.push_back(j);
                }
                for (; l <= r; l++)
                {
                    a[l] = 0;
                }

                i = r;
            }
        }
        for (int i = n; i >= n / 2; i--)
        {
            if (a[i] == 1)
            {
                r = i;
                for (int j = r - 1; j; j--)
                {
                    if (a[j] == 0)
                    {
                        l = j + 1;
                        break;
                    }
                }
                for (int j = r + 1; j <= n; j++)
                {
                    opt.push_back(j);
                }
                for (int j = l; j <= n; j++)
                {
                    opt.push_back(j);
                }
                i = l;
                for (; l <= r; l++)
                {
                    a[l] = 0;
                }
            }
        }
    }
    if (opt.size() > r)
    {
        cout<<-1;
        return 0;
    }
    cout << opt.size() << '\n';
    for (int i = 0; i < opt.size(); i++)
    {
        cout << opt[i] << ' ';
    }
}
