#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m,n,cnta = 0,cntb = 0,cnt;
    string a,b,add;


    cin>>n>>m>>a>>b;
    for (int i = 0; i < n; i++)
    {
        if(a[i] == '#')
        {
            cnta++;
        }
    }
    cnt = cnta;
    cntb = m - cnta;

    while (cntb >= 25 && cnta)
    {
        add += 'a';
        cntb -= 25;;
        cnta--;
    }
    char now = 'a';
    if(cnta + cntb <= 26)
    {
        for (int i = 0; i < cnta; i++)
        {
            add += 'a' + i;
        }
    }
    else
    {
        for (int i = 0; i < 26-cntb; i++)
        {
            add += 'a' + i;
            cnta--;
        }
        int i = 0;
        while (cnta)
        {
            add += 'a' + i;
            cnta--;
            i++;
            i%=26;
        }
    }
    for (int i = 0,j = 0; i < n; i++)
    {
        if(a[i] == '#')
        {
            a[i] = add[j++];
        }
    }
    cout<<a;
    
}