#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
    }int i = 1;
    for (; i <= ceil(1.0*n/3); i++)
    {
        cout << n << ' ';
    }
    for (; i <= n; i++)
    {
        cout << n - 1 << ' ';
    }
    
    
}