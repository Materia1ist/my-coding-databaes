#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll              // 此后所有 int 都是 64 位（等价于 #define int long long）
const int MAXN = 50005;
int n, m, sq, lnow = 1, rnow = 0, ans;
int a[MAXN],bak[MAXN],ansf[MAXN],ansb[MAXN];
struct quest
{
    int l, r, i;
    bool operator<(const quest& x)const
    {
        if(l/sq != x.l/sq)return l < x.l;
        if((l/sq) & 1) return r < x.r;
        return r > x.r;
    }   
};
vector<quest> q;

void add(int i)
{
    int x = a[i];
    bak[x]++;
    ans += bak[x] * 2 - 1;
}                                                                                                                                                                                                                                        
void del(int i)
{
    int x = a[i];
    bak[x]--;
    ans -= bak[x] * 2 + 1;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    sq = max(1LL,int(sqrt(n)));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int l,r;
        cin >> l >> r;
        if(l == r) {ansf[i] = 0, ansb[i] = 1; continue;}
        q.push_back({l,r,i});
    }
    sort(q.begin(), q.end());

    for(auto [l,r,i] : q)
    {
        while(lnow < l){del(lnow++);}
        while(rnow > r){del(rnow--);}
        while(lnow > l){add(--lnow);}
        while(rnow < r){add(++rnow);}
        
        ansf[i] = ans - (rnow - lnow + 1);
        ansb[i] = (rnow - lnow + 1) * (rnow - lnow);
        int temp = __gcd(ansf[i], ansb[i]);
        ansf[i] /= temp;
        ansb[i] /= temp;
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ansf[i] << '/' << ansb[i] << endl;
    }
    


}