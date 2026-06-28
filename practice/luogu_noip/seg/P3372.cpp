#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100000 + 3;
struct Node
{
    int sum, add, l, r;
} t[4 * N];
int a[N];
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
    t[p].sum = t[p * 2].sum + t[p * 2 + 1].sum;
    return;
}
inline void updata(int p)
{
    if (t[p].add == 0)
    {
        return;
    }
    
    int l = p * 2, r = p * 2 + 1;
    t[l].sum += (t[l].r - t[l].l + 1) * t[p].add;
    t[r].sum += (t[r].r - t[r].l + 1) * t[p].add;
    t[l].add += t[p].add;
    t[r].add += t[p].add;
    t[p].add = 0;
    return;
}
void add(int p, int l, int r, int c)
{
    if (t[p].l >= l && t[p].r <= r)
    {
        t[p].sum += (t[p].r - t[p].l + 1) * c;
        t[p].add += c;
        return;
    }
    updata(p);
    int mid = (t[p].l + t[p].r) / 2;
    if(mid < r)add(p * 2 + 1, l, r, c);
    if(mid >= l)add(p * 2,l,r,c);
    t[p].sum = t[p * 2].sum + t[p * 2 + 1].sum;
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
    if(mid < r)sum = sigma(p * 2 + 1, l, r);
    if(mid >= l)sum += sigma(p * 2 ,l,r);
    return sum;
}

signed main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1,1,n);
    while(m--)
    {
        int opt;
        cin >> opt;
        if(opt == 1)
        {
            int l,r,k;
            cin >> l >> r >> k;
            add(1,l,r,k);
        }
        else
        {
            int l,r;
            cin >> l >> r;
            cout << sigma(1,l,r)<<'\n';
        }
    }
}