//https://www.luogu.com.cn/problem/P3203

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n , m, l, cnt;
    cin >> n;
    l = sqrt(n);
    cnt = (n + l - 1) / l;
    int k[n+2],f[n+2],to[n+2];
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
        f[i] = 0;
        to[i] = 0; 
    }
    for (int b = 0; b < cnt; b++)
    {
        int L = b * l, R = min(n, (b+1) * l);
        for (int i = R - 1; i >= L; i--)
        {
            if(i + k[i] >= n)
            {
                to[i] = n;
                f[i] = 1;
            }
            else if(i + k[i] >= R)
            {
                to[i] = i + k[i];
                f[i] = 1;
            }else
            {
                f[i] = f[i+k[i]] + 1;
                to[i] = to[i+k[i]];
            } 
        }
    }
    
    
    cin >> m;
    while (m--)
    {
        int flag,a,b,ans = 0;
        cin >> flag;
        if(flag == 1)
        {
            cin >> a;
            while (a < n)
            {
                ans += f[a];
                a = to[a];
            }
            cout << ans << endl;
        }
        else
        {
            cin >> a >> b;
            k[a] = b;

            int L = (a/l) * l, R = min(n, L + l);

            for (int i = R - 1; i >= L; i--)
            {
                if(i + k[i] >= n)
                {
                    to[i] = n;
                    f[i] = 1;
                }
                else if(i + k[i] >= R)
                {
                    to[i] = i + k[i];
                    f[i] = 1;
                }else
                {
                    f[i] = f[i+k[i]] + 1;
                    to[i] = to[i+k[i]];
                } 
            }
        }
    }
    
    
}