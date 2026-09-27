#include <bits/stdc++.h>
using namespace std;
int n;
int bak[105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(bak,0,sizeof bak);
        for (int i = 0, temp; i < n; i++)
        {
            cin >> temp;
            bak[temp]++;
        }
        int cap = 0, cnt = 0;
        while (cnt < n)
        {
            for (int i = 100; i >= 1; i--)
            {
                if(bak[i])
                {
                    cap = bak[i];
                    
                    for(int x = 0; x < cap; x++) cout << i << ' ';
                    cnt += cap;
                    bak[i]-=cap;
                    for (int j = i-1; j >= 1; j--)
                    {
                        for(int x = 0; x < min(bak[j], cap); x++) cout << j << ' ';
                        cnt += min(bak[j], cap);
                        bak[j]-= min(bak[j], cap);
                    }
                }
            }
        }
        cout << endl;
    }
}