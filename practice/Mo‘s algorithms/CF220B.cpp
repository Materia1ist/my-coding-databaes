//https://www.luogu.com.cn/problem/CF220B
//普通莫队

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, m;                               // n 提到全局：push/pop 要按值域剪枝
int a[MAXN], bak[MAXN], cnt = 0, sq;    // bak[v] = 值 v 在当前区间内的出现次数
struct quest
{
    int l,r,i;
    bool operator<(const quest& b)const{

        if(l/sq != b.l/sq)return l < b.l;
        if((l/sq) & 1) return r < b.r;
        return r > b.r;
    }
}q[MAXN];

//map<int,int> bak;
//set<int> ans;

void push(int index)
{
    int x = a[index];
    if (x > n) return;

    if (bak[x] == x) cnt--;
    bak[x]++;
    if (bak[x] == x) cnt++;
}

void pop(int index)
{
    int x = a[index];
    if (x > n) return;

    if (bak[x] == x) cnt--;
    bak[x]--;
    if (bak[x] == x) cnt++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    sq = max(1, (int)sqrt((double)n));
    for (int i = 1; i <= n; i++)        // 1 起始：与询问的 1 起始下标对齐
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> q[i].l >> q[i].r;
        q[i].i = i;
    }
    sort(q, q+m);
    int lnow = 1, rnow = 0;
    int temp[m];                
    for (int i = 0; i < m; i++)         
    {    
        int l = q[i].l, r = q[i].r, j = q[i].i;
        while (lnow > l)push(--lnow);
        while (rnow < r)push(++rnow);
        while (lnow < l)pop(lnow++);
        while (rnow > r)pop(rnow--);
        temp[j] = cnt;
    }
    for (auto x : temp)
    {
        cout << x << endl;
    }
}