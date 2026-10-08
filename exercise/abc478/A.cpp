#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,b;
    cin >> n >> m;
    b = m/n;
    for (int i = 0; i < m - b*n; i++)
    {
        cout << b+1 << endl;
    }
    for (int i = m - b*n; i < n; i++)
    {
        cout << b << endl;
    }
    


}