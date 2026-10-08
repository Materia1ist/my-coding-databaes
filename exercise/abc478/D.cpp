#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x,l,r;
    bool operator<(const node& a)const
    {
        if(x == a.x)
        {
            if(l == a.l) return r < a.r;
            return l < a.l;
        }
        return x < a.x;
    }    
};

int main()
{
    int n,q;
    cin >> n >> q;
    int d[n+3];memset(d,0,sizeof d);
    node qwq[q];
    for (auto &[x,l,r] : qwq)
    {
        cin >> l >> r >> x;
    }
    sort(qwq,qwq+q);
    vector<node> opt;
    for (int i = 0; i < q; )
    {
        int x = qwq[i].x;
        int L = qwq[i].l, R = qwq[i].r;
        i++;
        while (i < q && qwq[i].x == x)
        {
            if(qwq[i].l <= R)R = max(R,qwq[i].r);
            else
            {
                opt.push_back({x,L,R});
                L = qwq[i].l;
                R = qwq[i].r;
            }
            i++;
        }
        opt.push_back({x,L,R});
    }
    for (auto [x,l,r] : opt)
    {
        d[l-1]++;
        d[r]--;
    }
    for (int i = 0,ans = 0; i < n; i++)
    {
        ans += d[i];
        cout << ans << ' ';
    }
    
    
    
    
}