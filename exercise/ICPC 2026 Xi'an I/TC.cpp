#include<bits/stdc++.h>
using namespace std;
#define tu true 
#define fl false
#define fi first
#define se second
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool s[n],hui[n],pin[n];
        char temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if(temp == '(')
            {
                s[i] = tu;
            }
            if(temp == ')')
            {
                s[i] = fl;
            }
            hui[i] = pin[i] = fl;
        }
        /*for (int i = 0; i < n; i++)
        {
            cout << (s[i] ? 1 : 0);
        }*/
        stack<pair<bool,int>> stk1,stk2;//1:hui,2:pin

        for (int i = 0; i < n; i++)
        {
            if(!stk2.empty() && s[i] == fl && stk2.top().fi == tu)
            {
                pin[i] = 1;
                pin[stk2.top().se] = 1;
                stk2.pop();
            }
            else stk2.push({s[i],i});
        }
        
    }
    
}