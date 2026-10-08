#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        stack<int> stk;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                stk.push(i+1);
            }
            if (s[i] == '2')
            {
                if (!stk.empty())
                {
                    ans.push_back(i+1);
                    stk.pop();
                }
            }
        }
        while (!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto x : ans)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
}