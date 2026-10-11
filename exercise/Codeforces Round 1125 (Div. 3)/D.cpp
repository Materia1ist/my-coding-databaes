//abcd take tot 1h20min
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
vector<pair<int,int>> q;
bool check(int x)
{
    int s = 0;
    for (auto [v,w] : q)
    {
        if(v >= x) break;
        s += x - v + w;
        if(s > k) return 0;
    }
    return s <= k;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int L = (int)4e18, R = (int)4e18, X = -(int)4e18, f = 0, M = (int)4e18;
        cin >> n >> k;
        q.clear();
        for (int i = 0,a,b,c,s; i < n; i++)
        {
            cin >> a >> b >> c;
            s = a+b+c;
            L = min(L,s);
            X = max(X,s);
            if(a == b && b == c)
            {
                f = 1;
                M = min(M,s);
            }
            else
            {
                int d = 0;
                if(a <= b && b <= c)d = min(b-a, c-b) + 1;
                q.push_back({s, 2*d});
            }
        }
        R = f ? M : X + k;
        sort(q.begin(),q.end());
        int mid;
        while (L < R)
        {
            mid = (L+R+1)/2;
            if(check(mid)) L = mid;
            else R = mid-1;
        }
        cout << L << endl;
    }
}
