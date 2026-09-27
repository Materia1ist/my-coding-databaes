//https://www.luogu.com.cn/problem/P17154
//Mo + Coordinate compression
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
int n,m,bs,tot,lnow,rnow;
int a[N+5], val[N+5], ans[11], bak[N+5],res[N+5][11];
struct quest
{
    int l,r,id;
    bool operator<(const quest& x)const{
        if(l/bs != x.l/bs) return l < x.l;
        if(l/bs & 1) return r < x.r;
        return r > x.r;
    }
};
vector<quest> q;
void disc()
{
    for (int i = 1; i <= n; i++) val[i] = a[i];
    sort(val+1,val+n+1);
    tot = unique(val+1,val+n+1) - (val+1);
    for(int i = 1; i <= n; i++) 
    {
        a[i] = lower_bound(val+1, val+tot+1, a[i]) - (val);
    }
}

void add(int i)
{
    int p = a[i];
    if(bak[p]++ == 0)
    {
        int l = p, r = p;
        while(bak[l-1] && val[l-1] == val[l]-1 && p - l <= 10)l--;
        if(l != p && p - l <= 10) ans[p-l]--;
        while(bak[r+1] && val[r+1] == val[r]+1 && r - p <= 10)r++;
        if(r != p && r - p <= 10) ans[r-p]--;
        if(r - l + 1 <= 10) ans[r-l+1]++;
    }
}
void del(int i)
{
    int p = a[i];
    if(--bak[p] == 0)
    {
        int l = p, r = p;
        while(bak[l-1] && val[l-1] == val[l]-1 && p - l <= 10)l--;
        if(l != p && p - l <= 10) ans[p-l]++;
        while(bak[r+1] && val[r+1] == val[r]+1 && r - p <= 10)r++;
        if(r != p && r - p <= 10) ans[r-p]++;
        if(r - l + 1 <= 10) ans[r-l+1]--;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        bs = max(1LL,(int)sqrt(n));
        q.clear();memset(bak,0,sizeof bak);memset(ans,0,sizeof ans);
        for(int i = 1; i <= n; i++)cin >> a[i];
        disc();
        for (int i = 1, l, r; i <= m; i++)
        {
            cin >> l >> r;
            q.push_back({l,r,i});
        }
        sort(q.begin(),q.end());
        
        lnow = 1,rnow = 0;
        for(auto [l,r,i] : q)
        {
            while(l<lnow)add(--lnow);
            while(r>rnow)add(++rnow);
            while(l>lnow)del(lnow++);
            while(r<rnow)del(rnow--);
            for (int j = 0; j < 10; j++)res[i][j] = ans[j+1];
        }

        for(int i = 1; i <= m; i++)
        {
            for(int j = 0; j < 10; j++)cout << (res[i][j]%10);
            cout << '\n';
        }
    }
    
}




    