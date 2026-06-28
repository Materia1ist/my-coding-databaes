#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        string s,m = "respect";
        cin>>s;
        int ans = 0,n,div;
        cin>>n;
        if(n == 0){
             bool flag = 1;
            for (int i = 0 ;i < 7; i++)
            {
                if(s[i] != m[i]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                ans++;
            }
        }
        else
        while(n--)
        {
            cin>>div;
            bool flag = 1;
            for (int i = 0 ;i < 7; i++)
            {
                if(s[div+i] != m[i]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                ans++;
            }
        }
        
        cout<<ans<<'\n';
    }
    
}