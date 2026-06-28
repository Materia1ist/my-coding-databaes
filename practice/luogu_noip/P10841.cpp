#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s,now;

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        cin >> n >> s;
        ans = n;
        now.clear();
        for (int i = 1; i < n; i++)
        {
            if(s[i] == s[i-1])
            {
                ans--; i+=2;
            }
        }
        cout<<ans<<'\n';
    }
    
}