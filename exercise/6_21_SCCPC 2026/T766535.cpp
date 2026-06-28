#include<bits/stdc++.h>
using namespace std;

bool judge1(string s)//奇数回文
{
    vector<int> cnt1(26, 0),cnt2(26, 0);//奇数位和偶数位的字符出现次数
    for(int i = 0; i < s.size(); i++)
        if(i % 2 == 0)
            cnt1[s[i] - 'a']++;
        else
            cnt2[s[i] - 'a']++;
    int odd_cnt1 = 0, odd_cnt2 = 0;// even_cnt = 0;
    for(int i = 0; i < 26; i++)
    {
        if(cnt1[i] % 2 == 1)odd_cnt1++;
        if(cnt2[i] % 2 == 1)odd_cnt2++;
    }
    if((s.size() % 4 == 1 && odd_cnt1 == 1 && odd_cnt2 == 0) || (s.size() % 4 == 3 && odd_cnt1 == 0 && odd_cnt2 == 1))return true;
    return false;
}

bool judge2(string s)//偶数回文
{
    vector<int> cnt1(26, 0),cnt2(26, 0);//奇数位和偶数位的字符出现次数
    for(int i = 0; i < s.size(); i++)
        if(i % 2 == 0)
            cnt1[s[i] - 'a']++;
        else
            cnt2[s[i] - 'a']++;
    for(int i = 0; i < 26; i++)
    {
        if(cnt1[i] != cnt2[i])return false;
    }
    return true;
}

int main()
{
    int N;
    string S;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> S;
        if(S.size() % 2 == 1)
        {
            if(judge1(S))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            if(judge2(S))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
}