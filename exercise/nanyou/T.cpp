#include <bits/stdc++.h>
using namespace std;

struct trie
{
    int nex[1000000][26], cnt;
    bool exist[1000000];
    int sum[1000000];

    int insert(char *s, int l, int j)
    {
        int p = 0,ans = 0;
        for (int i = 0; i < l; i++)
        {
            int c = s[i] - 'a';
            if (!nex[p][c])
            {
                if(sum[p])//geng xin da an
                {
                    ans += (cnt^j) * sum[p];
                }
                nex[p][c] = ++cnt;
            }
            sum[p]++;
            p = nex[p][c];
        }
        exist[p] = true;
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    int ans = 0;

    trie t;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= s.length(); j++)
        {
            t.insert();
        }
    }
}