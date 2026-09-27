#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 100000;
int cnt0[N + 5], cnt1[N + 5];
bool a[N + 5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int ans = 0x3f3f3f3f;
        memset(cnt0, 0, sizeof cnt0);
        memset(cnt1, 0, sizeof cnt1);

        vector<int> s;

        string str;
        cin >> str;

        for (int i = 0; i < n; i++)
        {
            a[i] = str[i] - '0';
        }

        cnt0[0] = !a[0];
        cnt1[0] = a[0];

        for (int i = 1; i < n; i++)
        {
            cnt0[i] = cnt0[i - 1] + !a[i];
            cnt1[i] = cnt1[i - 1] + a[i];

            if (a[i] != a[i - 1])
            {
                s.push_back(i - 1);
            }
        }

        if (a[0] == 1)
        {
            ans = cnt0[n - 1];
        }
        else if (s.size() == 0)
        {
            ans = 0;
        }
        else
        {
            s.push_back(n - 1);

            for (auto p : s)
            {
                ans = min(ans, cnt1[p] + cnt0[n - 1] - cnt0[p]);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}