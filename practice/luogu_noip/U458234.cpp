#include <bits/stdc++.h>
using namespace std;
long long m, n, ans,k;
int t[200005];
bool is1[200005], is2[200005], is3[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        for (int j = 0; j < m; j++)
        {
            if (is3[t[i]+j])
            {
            }
            else if (is2[t[i]+j])
            {
                is2[t[i]+j] = 0;
                is3[t[i]+j] = 1;
            }
            else if (is1[t[i]+j] )
            {
                is1[t[i]+j] = 0;
                is2[t[i]+j] = 1;
            }
            else
            {
                is1[t[i]+j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        for (int j = 0; j < m; j++)
        {
            if (is2[t[i]+j])
            {
                temp++;
            }
            if (is1[t[i]+j])
            {
                k++;
                is1[t[i]+j] = 0;
            }
        }
        ans = ans<temp?temp:ans;
    }
    ans += m + k;
    cout << ans;
}