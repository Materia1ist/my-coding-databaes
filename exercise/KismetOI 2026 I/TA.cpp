#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,t;
    cin >> n >> m;
    cout << endl << flush;
    vector<int> now;
    for(int i = 1; i <= n ; i++)
    {
        now.push_back(i);
    }
    while (1)
    {
        cout << "? " << now.size() << ' ';
        for (int i = 0; i < now.size(); i++)
        {
            cout << now[i] << ' ';
        }
        cout << endl << flush;
        cin >> t;
        vector<int> a;
        int temp;
        a.push_back(1);
        for (int i = 0; i < t; i++)
        {
            cin >> temp;
            a.push_back(now[temp-1]);
        }
        a.push_back(n);
        cout << endl << flush;
        if(t == 1)
        {
            cout << "! " << a[1];
            return 0;
        }
        now = a;
    }
    
}