#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100000 + 3;
int mod;
struct Node
{
    int sum, add, mul, l, r;
} t[N * 4];
int a[N];
void updata(int p)
{
    if (t[p].add == 0 && t[p].mul == 1)
    {
        return;
    }
    int l = p * 2, r = l + 1;
    t[l].sum = (t[l].sum * t[p].mul + (t[l].r - t[l].l + 1) * t[p].add) % mod;
    t[r].sum = (t[r].sum * t[p].mul + (t[r].r - t[r].l + 1) * t[p].add) % mod;
    t[l].mul = (t[l].mul * t[p].mul) % mod;
    t[r].mul = (t[r].mul * t[p].mul) % mod;
    t[l].add = (t[l].add * t[p].mul + t[p].add ) % mod;
    t[r].add = (t[r].add * t[p].mul + t[p].add ) % mod;
    t[p].add = 0;
    t[p].mul = 1;
}
void build(int p, int l, int r)
{
    t[p].l = l;
    t[p].r = r;
    if (l == r)
    {
        t[p].sum = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    t[p].sum = (t[p * 2].sum + t[p * 2 + 1].sum) % mod;
    t[p].add = 0;
    t[p].mul = 1;
}
void add(int p, int l, int r, int c)
{
    if (t[p].l >= l && t[p].r <= r)
    {
        t[p].sum =(t[p].sum + (t[p].r - t[p].l + 1) * c) % mod;
        t[p].add = (t[p].add + c) % mod;
        return;
    }
    updata(p);
    int mid = (t[p].l + t[p].r) / 2;
    if (mid >= l)
        add(p * 2, l, r, c);
    if (mid < r)
        add(p * 2 + 1, l, r, c);
    t[p].sum = (t[p * 2].sum + t[p * 2 + 1].sum) % mod;
}
void mul(int p, int l, int r, int c)
{
    if (t[p].l >= l && t[p].r <= r)
    {
        t[p].mul = (t[p].mul * c) % mod;
        t[p].sum = (t[p].sum * c) % mod;
        t[p].add = (t[p].add * c) % mod;
        return;
    }
    updata(p);
    int mid = (t[p].l + t[p].r) / 2;
    if (mid >= l)
        mul(p * 2, l, r, c);
    if (mid < r)
        mul(p * 2 + 1, l, r, c);
    t[p].sum = (t[p * 2].sum + t[p * 2 + 1].sum) % mod;
}
int sigma(int p, int l, int r)
{
    if (t[p].l >= l && t[p].r <= r)
    {
        return t[p].sum;
    }
    updata(p);
    int sum = 0;
    int mid = (t[p].l + t[p].r) / 2;
    if (mid >= l)
        sum += sigma(p * 2, l, r);
    if (mid < r)
        sum += sigma(p * 2 + 1, l, r);
    return sum % mod;
}
signed main()
{
    int n, m;
    cin >> n >> m >> mod;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    while (m--)
    {
        int chk;
        cin >> chk;
        int x, y;
        int k;
        if (chk == 1)
        {
            cin >> x >> y >> k;
            mul(1, x, y, k);
        }
        else if (chk == 2)
        {
            cin >> x >> y >> k;
            add(1, x, y, k);
        }
        else
        {
            cin >> x >> y;
            printf("%d\n", sigma(1, x, y));
        }
    }
    return 0;
}