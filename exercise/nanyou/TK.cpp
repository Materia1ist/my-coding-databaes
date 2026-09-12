#include <bits/stdc++.h>
using namespace std;
int bak[10];

bool judge(int n)
{
    int a[10];
    for (int i = 0; i <= 9; i++)
        a[i] = bak[i];
    if (a[0] >= n)
    {
        a[0] -= n;
    }
    else if (a[0] + (a[1] / 2) >= n)
    {
        int temp = n - a[0];
        a[0] = 0;
        a[1] -= temp * 2;
    }
    else
        return 0;

    // dig 3
    if ((a[0] + a[1] + a[2] + a[3] + a[4] + a[5]) >= n)
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        for (int i = 0; i <= 9; i++)
            bak[i] = 0;
        for (auto i : s)
        {
            bak[i - '0']++;
        }

        int l = 0, r = n / 4, mid, ans = 0;
        while (l < r)
        {
            int mid = (l + r + 1) / 2; 

            if (judge(mid))
            {
                l = mid;
                ans = max(ans,mid);
            }
                
            else
                r = mid - 1;
        }
        cout << ans << endl;
    }
}