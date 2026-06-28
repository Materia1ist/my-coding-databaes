#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    cout << '/';
    for (int i = 0; s[i] != ']' ; i++)
    {
        if(s[i] <= 'Z' && s[i] >= 'A')
        {
            cout << char(s[i] - 'A' + 'a');
        }
    }
    
}