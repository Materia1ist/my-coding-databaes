#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 2)
            cout << "3\n2 2 2\n";
        else if(n == 3) cout << "3\n4 4 4\n";
        else
        {
            vector<int> ans;

            if((n + 1) % 3)
            {
                
                for (int i = (n-1) * 2; i >= 4; i-=2)
                {
                   ans.push_back(i);
                }
                for (int i = (n-1) * 2; i >= 4; i-=2)
                {
                    ans.push_back(i);
                }
                for (int i = (n-1) * 2; i >= 4; i-=2)
                {
                    ans.push_back(i);
                }
            }else
            {
                for (int i = (n-1) * 2; i >= 4; i-=2)
                {
                    ans.push_back(i);
                }
                for (int i = (n-1) * 2 + 1; i >= 3; i-=2)
                {
                    ans.push_back(i);
                }
                for (int i = (n-1) * 2; i >= 4; i-=2)
                {
                    ans.push_back(i);
                }
            }
            cout << ans.size() << endl;
            for(auto v : ans)
            {
                cout << v << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}