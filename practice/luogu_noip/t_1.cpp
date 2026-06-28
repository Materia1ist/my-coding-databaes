#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
int len,dp[1000005],dif[1000005][128],ans = 0;
string s;
int getcnt (char a,char b,int p)
{
    int cnt = 0;
    for (int i = p-1; i; i--)
    {
        if(s[i] != a != b)
        {
            cnt += i - dif[i][s[i]] - dif[i][a] - dif[i][b] + 1;
            cnt %= MOD;
        }  
    }
    return cnt;
}
int main()
{
    
    
    cin >> s;
    len = s.length();
    dif[0][s[0]];
    for (int  i = 1; i < len; i++)
    {
        for(int j = 1; j < 128; j++)
        {
            dif[i][j] = dif[i-1][j];
        }
        ++dif[i][s[i]];
    }
    // for (int i = 0; i < len; i++)
    // {
    //     cout<<' '<<dif[i];
    // }
    
    for (int a = len-4; a >= 2; a--)
    {
        for (int b = a+1; b < len; b++)
        {
            int cnt = getcnt(s[a],s[b],a-1);
            cout<<cnt<<'\n';
            if(cnt != 0)
            {
                int flag = 1,cnta = 1,cntb = 1;
                for(int i = b+1; i < len;i++)
                {
                    if(flag == 1)
                    {
                        if(s[i] == s[a])
                        {
                            cnta++;
                            flag = 2;
                        }
                    }
                    else
                    {
                        if(s[i] == s[b])
                        {
                            cntb++;
                            flag = 1;
                        }
                    }
                }
                dp[a] += min(cnta,cntb) - 1;
                dp[a] %= MOD;
            }
            dp[a]+=dp[a+1];
            dp[a] %= MOD;
        }
    }
    for(int i = 1; i < len;i++)
        cout<<dp[i]<<' ';
}