#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    long long n = s.length();
    vector<int> l(26,-1),r(26,-1);
    long long ans = n * (n-1) / 2;
    for(int i = 0 ; i < n ; i++)
    {
        if(l[s[i]-'a'] == -1)
        {
            l[s[i]-'a'] = i;
        }
    }
    for(int i = n-1 ; i >= 0 ; i--)
    {
        if(r[s[i]-'a'] == -1)
        {
            r[s[i]-'a'] = i;
        }
    }
    for(int i = 0 ; i < 26 ; i++)
    {
        if(l[i] != -1)
        {
            for(int j = 0 ; j < 26 ; j++)
            {
                if(r[j] != -1 && l[i] < r[j])
                {
                    ans--;
                }
            }
        }
    }
    cout << ans << endl;
}
/*  //version 1.0 O(n^2) 
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    bool fro[n][26] = {false}, bak[n][26] = {false};
    for(int i = 0 ; i < n ; i++)
    {
        if(i > 0)
        {
            for(int j = 0 ; j < 26 ; j++)
            {
                fro[i][j] = fro[i-1][j];
            }
        }
        fro[i][s[i]-'a'] = true;
    }
    for(int i = n-1 ; i >= 0 ; i--)
    {
        if(i < n-1)
        {
            for(int j = 0 ; j < 26 ; j++)
            {
                bak[i][j] = bak[i+1][j];
            }
        }
        bak[i][s[i]-'a'] = true;
    }
    int ans = 0;
    for(int l = 0 ; l < n-1 ; l++)
    {
        for(int r = l+1 ; r <= n-1 ; r++)
        {
            if((fro[l-1][s[l]-'a'] && l > 0) || (bak[r+1][s[r]-'a'] && r < n-1))
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
    */