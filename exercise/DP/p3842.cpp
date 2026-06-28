#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n ;
    int ln,rn,ll = 1,rl = 1;
    vector<int> l(n+1,0),r(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        cin >> ln >> rn;
        l[i] = min (l[i-1] + abs(rn - ll) + rn - ln, r[i-1] + abs(rn - rl) + rn - ln);
        r[i] = min (l[i-1] + abs(ln - ll) + rn - ln, r[i-1] + abs(ln - rl) + rn - ln);
        ll = ln, rl = rn;
    }
    cout << min(l[n] + n - ln,r[n] + n - rn) + n - 1;
}

/*int main()
{
    int n,l,r,now = 1,ans = 0;
    cin >> n ;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        if(now <= l)
        {
            ans += r - now;
            now = r;
        }
        else if(now >= r)
        {
            ans += now - l;
            now = l;
        }
        else
        {
            ans += min(r - now, now - l);
            if(r - now < now - l) now = r;
            else now = l;
        }
    }
    if (now != n) ans += n - now;
    cout << ans + n - 1;
    return 0;
}*/