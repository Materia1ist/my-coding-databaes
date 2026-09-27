#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        cout << (1 << (n-k+1)) + (k-1) * 2 << endl;
    }
    
}