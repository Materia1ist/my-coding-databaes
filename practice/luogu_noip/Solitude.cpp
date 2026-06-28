#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, ans = 0;
int a[500005], b[500005], c[500005]; // a->max,b->min

struct pos
{
    int len;
    int a[500005];
    int s;
    pos(int len, int s, int a[])
    {
        this->len = len;
        this->s = s;
        for (int i = 1; i <= len; i++)
        {
            this->a[i] = a[i];
        }
    }
};

inline int read()
{
    int s = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
        s = s * 10 + c - '0', c = getchar();
    return s;
}

int bfs()
{
    int max_s = 0;
    queue<pos> q;
    pos t(1, 0, a);
    t.a[0] = 0, t.a[n + 1] = 0;
    q.push(t);
    t.a[1] = b[1];
    q.push(t);
    while (!q.empty())
    {
        t = q.front();
        q.pop();
        if (t.len == n && t.s >= max_s)
        {
            if (t.a[t.len - 2] < t.a[t.len] && t.a[t.len + 1] > t.a[t.len])
                t.s++;
            if (t.s > max_s)
                max_s = t.s;
            if (t.s == max_s)
            {
                int Max = 0, Min = 1000000007;
                for (int i = 1; i <= t.len; i++)
                {
                    if (t.a[i] > Max)
                        Max = t.a[i];
                    if (t.a[i] < Min)
                        Min = t.a[i];
                }
                if (ans < Max - Min)
                {
                    ans = Max - Min;
                }
            }
        }
        if (t.len != n)
        {
            t.a[++t.len] = a[t.len];
            if (t.a[t.len - 2] < t.a[t.len - 1] && t.a[t.len] > t.a[t.len - 1])
            {
                t.s++;
                q.push(t);
                t.s--;
            }
            else
            {
                q.push(t);
            }
            t.a[t.len] = b[t.len];
            if (t.a[t.len - 2] < t.a[t.len - 1] && t.a[t.len] > t.a[t.len - 1])
            {
                t.s++;
                q.push(t);
                t.s--;
            }
            else
            {
                q.push(t);
            }
        }
    }
    return max_s;
}
int main()
{

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] = read();
    }
    cout << bfs() << '\n' << ans;
    return 0;
}