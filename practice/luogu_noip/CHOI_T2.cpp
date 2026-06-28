#include<bits/stdc++.h>
using namespace std;
struct nobe
{
    int cost;
    double p;
};
bool cmp (nobe a,nobe b)
{
    return a.p < b.p;
}
int main()
{
    int n,m,s,k,x;
    vector<nobe> a;
    cin >> n >> m >> s >> k >> x;
    for (int i = 0; i < n; i++)
    {
        int p1;
        double p2;
        cin >> p1 >> p2;
        a.push_back({p1,p2});
    }
    if (k == 0)
    {
        double ans = 1;
        sort(a.begin(),a.end(),cmp);
        for (auto i : a)
        {
            if (m == 0)
            {
                break;
            }
            
            if (i.cost >= s)
            {
                ans *= 1 - i.p;
                m--;
            }
        }
        if (m)
        {
            cout << -1;
            return 0;
        }
        
        ans = 1 - ans;
        printf("%.5f",ans);
    }
    

}