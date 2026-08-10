#include<bits/stdc++.h>
using namespace std;

void solve()
{
    

    int n;
    cin >> n;
    
    vector<int> a(n,0);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    int lk = a[1] - a[0] - 1,rk = a[n-1] - a[n-2] - 1;
    cout << a[n-1] - a[0] + 1 - n - min(lk,rk) << endl;

}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
}