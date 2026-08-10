#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,ans = 1;
    cin >> n;
    n/=2;
    ans <<= n;
    ans--;
    ans <<= n;
    cout << ans << endl;

}