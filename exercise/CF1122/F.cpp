//https://codeforces.com/contest/2266/problem/F

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2 * 1e5;
int n,l,r,mid,sum;
vector<pair<int,int>>a;
bool check(int p)
{
    
    int debt = 1,ext = 0,gap = 0,now = p,i = (lower_bound(a.begin(), a.end(),pair<int, int>{p, 0}) - a.begin()) - 1;//0-base
    //cout << nxt;//text
    while(i >= 0)
    {
        auto [x,y] = a[i];
        gap = now - x - 1;
        if(gap >= 63)return 0;
        if(debt > sum/(1LL << gap))return 0;

        debt <<= gap;
        if (x == 0){ext += y; break;}


        if(debt > y)debt += debt - y;
        else ext += y - debt;
        if(debt > sum)return 0;
        now = x;
        i--;
    }
    return ext >= debt;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        a.clear();
        l = 0,r = 0,sum = 0;
        for (int i = 0,x,y; i < n; i++)
        {
            cin >> x >> y;
            a.push_back({x,y});
            l = max(l,x);
            sum += y;
        }
        sort(a.begin(),a.end());
        if(a[0].first != 0)
        {
            a.insert(a.begin(),{0,0});
        }
        //if(a[0].first != 0 || (a[0].first == 0 && a[0].second == 0)) {cout << r << endl; continue;}
        r = 1e9+100;
        while(l < r)
        {
            mid = (l+r+1)/2;
            if(check(mid)) l = mid;
            else r = mid-1;
        }
        
        cout << l << endl;
    }
    
}