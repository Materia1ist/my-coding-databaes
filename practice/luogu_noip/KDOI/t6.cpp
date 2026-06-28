#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k, t;
    cin >> n >> m >> k >> t;

    vector<vector<vector<int>>> box(n, vector<vector<int>>(m));

    while (t--)
    {
        int a, x, y;
        cin >> a >> x >> y;
        --x;
        --y;

        vector<int> &stk = box[x][y];
        if (stk.size() == k)
        {
            int min_val = stk[0], min_idx = 0;
            for (int i = 1; i < k; ++i)
            {
                if (stk[i] < min_val)
                {
                    min_val = stk[i];
                    min_idx = i;
                }
            }
            cout << min_val << " " << k - min_idx - 1 << endl;
            stk.erase(stk.begin() + min_idx);
        }
        else
        {
            cout << "-1" << endl;
        }
        stk.push_back(a);
    }

    return 0;
}
