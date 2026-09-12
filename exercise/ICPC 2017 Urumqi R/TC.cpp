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
        cin >> n;

        vector<int> preDp(n + 2), dp(n + 2);
        vector<int> preRank(n + 2), pathRank(n + 2);
        vector<int> val(n + 2);
        vector<char> letter(n + 2);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
                cin >> val[j] >> letter[j];

            if (i == 1)
            {
                dp[1] = val[1];
                pathRank[1] = 0;
            }
            else
            {
                vector<tuple<char, int, int>> order;

                for (int j = 1; j <= i; j++)
                {
                    int parentRank;

                    if (j == 1)
                    {
                        dp[j] = val[j] + preDp[j];
                        parentRank = preRank[j];
                    }
                    else if (j == i)
                    {
                        dp[j] = val[j] + preDp[j - 1];
                        parentRank = preRank[j - 1];
                    }
                    else
                    {
                        dp[j] = val[j] + max(preDp[j - 1], preDp[j]);

                        if (preDp[j - 1] > preDp[j])
                            parentRank = preRank[j - 1];
                        else if (preDp[j - 1] < preDp[j])
                            parentRank = preRank[j];
                        else
                            parentRank = min(preRank[j - 1], preRank[j]);
                    }

                    order.emplace_back(letter[j], parentRank, j);
                }

                sort(order.begin(), order.end());

                int rank = -1;
                char lastLetter = 0;
                int lastParentRank = -1;

                for (auto [ch, parentRank, id] : order)
                {
                    if (rank == -1 || ch != lastLetter || parentRank != lastParentRank)
                    {
                        rank++;
                        lastLetter = ch;
                        lastParentRank = parentRank;
                    }
                    pathRank[id] = rank;
                }
            }

            swap(dp, preDp);
            swap(pathRank, preRank);
        }

        int maxSum = *max_element(preDp.begin() + 1, preDp.begin() + n + 1);
        vector<int> ans;

        for (int i = 1; i <= n; i++)
        {
            if (preDp[i] == maxSum)
                ans.push_back(i);
        }

        sort(ans.begin(), ans.end(), [&](int x, int y)
             {
            if (preRank[x] != preRank[y])
                return preRank[x] < preRank[y];
            return x < y; });

        int m = ans.size();
        for (int i = 0; i < m; i++)
        {
            if (i)
                cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}
