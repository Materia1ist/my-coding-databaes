#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,len,ans = 0;
        string s;
        char c;
        cin >> n >> c >> s;
        int l = 0, r = n-1;
        while (l < r)
        {
            if(s[l] != s[r] && s[l] != c && s[r] != c) ans += 2;
            else if(s[l] != s[r] && (s[l] == c || s[r] == c)) ans += 1;
            l++;
            r--;
        }
        cout << ans << endl;



    }
    
}