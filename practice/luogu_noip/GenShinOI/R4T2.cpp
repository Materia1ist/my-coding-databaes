#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,n;
    cin >> T >> n;
    
        if (n == 1)
    {
         while (T--)
        {
            int q;
            cin >> q;
            if (q%2)
            {
                putchar('F');
            }
            else
            {
                putchar('B');
            }
        }
        return 0;
    }
    if (n == 2)
    {
         while (T--)
        {
            int q;
            cin >> q;
            if (q != 3)
            {
                putchar('F');
            }
            else
            {
                putchar('B');
            }
        }
        return 0;
    }
    bool f[n*n];
    memset(f,1,sizeof(f));
    vector<int>a;
    map <int,bool> ans;
    for (int i = 1; i*i < n; i++)
    {
        a.push_back(i*i);
    }
    for (int i = 1; i < n; i++)
    {
        a.push_back(i * n);
    }

    int cnt = 0;
    for (int i = 0; i < n*n; i++)
    {
        if (f[i] == 1)
        {
            for (int j = 0; i + a[j] < n * n && j < a.size(); j++)
            {
                a[i + a[j]] = 0;
            }
            cnt ++;
            ans[i] = 1;
        }
        if(cnt >= n)break;
    }

    while (T--)
    {
        int q;
            cin >> q;
            if (ans[q] == 0)
            {
                putchar('F');
            }
            else
            {
                putchar('B');
            }
    }
    

    
    

}