#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100005;
struct Node
{
    double sum,pow,add;
    int l,r;
}t[4 * N];
double a[N];
void updata(int p)
{
    if (t[p].add == 0)
    {
        return;
    }
    int l = p * 2,r = p * 2 + 1;

    t[l].pow += (t[l].r - t[l].l + 1) * t[p].add * t[p].add + 2 * t[p].add * t[l].sum; 
    t[r].pow += (t[r].r - t[r].l + 1) * t[p].add * t[p].add + 2 * t[p].add * t[r].sum; 
    t[l].sum += (t[l].r - t[l].l + 1) * t[p].add;
    t[r].sum += (t[r].r - t[r].l + 1) * t[p].add;
    t[l].add += t[p].add;
    t[r].add += t[p].add;
    t[p].add = 0;
}
void build(int p,int l,int r)
{
    t[p].l = l;
    t[p].r = r;
    if (l == r)
    {
        t[p].sum = a[l];
        t[p].pow = a[l] * a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(p * 2,l,mid);
    build(p * 2 + 1, mid + 1, r);
    t[p].pow = t[p * 2].pow + t[p * 2 + 1].pow;
    t[p].sum = t[p * 2].sum + t[p * 2 + 1].sum;
}
void add(int p,int l,int r,double c)
{
    if(l <= t[p].l && t[p].r <= r)
    {
        t[p].add += c;
        t[p].pow += (t[p].r - t[p].l + 1) * c * c + 2 * c * t[p].sum; 
        t[p].sum += c * (t[p].r - t[p].l + 1);
        return;
    }
    updata(p);
    int mid = (t[p].l + t[p].r) / 2;
    if(mid >= l) add(p * 2, l, r, c);
    if (mid < r) add(p * 2 + 1, l, r,c);
    t[p].pow = t[p * 2].pow + t[p * 2 + 1].pow;
    t[p].sum = t[p * 2].sum + t[p * 2 + 1].sum;
}
double sigma(int p, int l, int r)
{
    if (t[p].l >= l && t[p].r <= r)
    {
        return t[p].sum;
    }
    updata(p);
    double sum = 0;
    int mid = (t[p].l + t[p].r) / 2;
    if(mid < r)sum += sigma(p * 2 + 1, l, r);
    if(mid >= l)sum += sigma(p * 2 ,l,r);
    return sum;
}
double sigmapow(int p, int l, int r)
{
    if (t[p].l >= l && t[p].r <= r)
    {
        return t[p].pow;
    }
    updata(p);
    double sum = 0;
    int mid = (t[p].l + t[p].r) / 2;
    if(mid < r)sum += sigmapow(p * 2 + 1, l, r);
    if(mid >= l)sum += sigmapow(p * 2 ,l,r);
    return sum;
}
signed main()
{
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1,1,n);
    while (m--)
    {
        int opt,x,y;
        double k;
        cin >> opt;
        if (opt == 1)
        {
            cin >> x >> y >> k;
            add(1,x,y,k);
        }
        if (opt == 2)
        {
            cin >> x >> y;
            printf("%.4f\n",(1.0 * sigma(1,x,y))/(y - x + 1));
        }
        if (opt == 3)
        {
            cin >> x >> y;
            printf("%.4f\n",(1.0 * sigmapow(1,x,y))/(y - x + 1) - pow((1.0 * sigma(1,x,y))/(y - x + 1),2));
        }
    }
    
}