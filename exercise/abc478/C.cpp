#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n],b[n];
    int l = 0, r = n-1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b,b+n);
    while (l < n && a[l] == b[l])l++;
    while (r >= 0 && a[r] == b[r])r--;
    if(l > r){cout << "Yes";return 0;}
    cout <<(r - l + 1 <= k?"Yes":"No");
    
    
    
}