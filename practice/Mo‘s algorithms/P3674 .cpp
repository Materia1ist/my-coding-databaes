//https://www.luogu.com.cn/problem/P3674
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, m, bs, lnow = 1, rnow = 0;
struct quest
{
    int k, l, r, x, i;
    bool operator<(const quest& oth)const{
        if(l/bs != oth.l/bs) return l < oth.l;
        if((l/bs) & 1) return r < oth.r;
        return r > oth.r;
    }
}q[N+5];

int a[N+5], bak[N+5], ans[N+5];
bitset<N+5> now1, now2;

void add(int i)
{
    int x = a[i];
    if(bak[x]++ == 0)now1[x] = now2[N-x] = 1;
}
void del(int i)
{
    int x = a[i];
    if(--bak[x] == 0)now1[x] = now2[N-x] = 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    bs = max(1,int(sqrt(n)));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        int k, l, r, x;
        cin >> k >> l >> r >> x;
        q[i] = {k,l,r,x,i};
    }
    sort(q,q+m);

    for (int i = 0; i < m; i++)
    {
        const auto [k,l,r,x,id] = q[i];    
        while (lnow > l) add(--lnow);
        while (rnow < r) add(++rnow);
        while (lnow < l) del(lnow++);
        while (rnow > r) del(rnow--);
        if(k == 1)
        {
            if((now1 & (now1 << x)).any())ans[id] = 1;
        }
        if(k == 2)
        {  
            if((now1 & (now2 >> (N-x))).any())ans[id] = 1;
        }
        if(k == 3)
        {
            for(int j = 1; j <= sqrt(x); j++)
            {
                if(x%j == 0 && now1[x/j] && now1[j])
                {
                    ans[id] = 1;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << (ans[i] ? "hana\n" : "bi\n");
    }
    
    
    
    

}