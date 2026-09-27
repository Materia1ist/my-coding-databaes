#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int>a,b;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            a.push_back(temp);
            b.push_back(temp-i);
        }
        
        sort(b.begin(), b.end());

        int ans = 1, cur = 1;

        for (int i = 1; i < n; i++)
        {
            if (b[i] == b[i - 1])
            {
                continue; 
            }
            else if (b[i] == b[i - 1] + 1)
            {
                cur++;
            }
            else
            {
                cur = 1;
            }
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }
}