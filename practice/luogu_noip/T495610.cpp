#include <bits/stdc++.h>
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * f;
}

inline void write(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

int main()
{
    int T = read();
    while (T--)
    {
        int n = read();
        vector<int> p(n + 1);
        vector<bool> flag1(n + 1, 0), flag2(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            p[i] = read();
        }

        int ans = 0, Min = 1, Max = n;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == Max)
            {
                Max--;
                flag2[i+1] = 1;
            }
            else if (a[i] == Min)
            {
                Min++;
                flag2[i+1] = 1;
            }
            else
            {
                i = (n+i)/2;
            }
        }
        
    }

    return 0;
}
