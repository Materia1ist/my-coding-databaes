#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c = 0,d = 0;
    cin>>a>>b;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'S')
        {
            c++;
        }
        else
        {
            d++;
        }
    }
    if (a+b > c+d)
    {
        cout << -1;
        return 0;
    }
    if(a <= c && b <= d)
    {
        cout<<0;
        return 0;
        
    }
    cout << min(abs(a-c),abs(b-d));

}