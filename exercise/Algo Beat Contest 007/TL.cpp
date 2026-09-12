#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string pat, int m, vector<int> &LPS)
{
    int l = 0;
    LPS[0] = 0;
    int i = 1;

    while (i < m)
    {
        if (pat[i] ==
            pat[l])
        {
            l++;
            LPS[i] = l;
            i++;
        }
        else
        {
            if (l != 0)
            {
                l = LPS[l - 1];
            }
            else
            {
                LPS[i] = 0;
                i++;
            }
        }
    }
}

bool KMP(string pat,
         string text)
{
    int m = pat.length();
    int n = text.length();

    vector<int> LPS(m);
    computeLPSArray(pat, m, LPS);

    int i = 0;
    int j = 0;
    while (i < n)
    {

        if (pat[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            return 1;
        }

        else if (i < n && pat[j] != text[i])
        {
            if (j != 0)
            {
                j = LPS[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return 0;
}

int main()
{
    int n,m,ans = 0;
    cin >> n >> m;
    string s[n];
    string t;
    bool flag[n];
    for (int i = 0; i < n; i++)
    {
        flag[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < i; j++)
        {
            if(s[i] == s[j])flag[i] = flag[j] = 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        for (int j = 0; j < n; j++)
        {
            if(flag[j] == 0)
            {
                if(KMP(t,s[j])) flag[j] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(flag[i])ans++;
    }
    cout<<ans;
    
}