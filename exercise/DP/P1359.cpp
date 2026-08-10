#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n ;
    int m[n+3][n+3];
    for(int i = 0 ; i < n+3 ; i++)
    {
        for (int j = 0 ; j < n+3 ; j++)
        m[i][j] = 0;
    }
    for(int i = 1; i < n ; i++)
    {
        for (int j = i ; j < n ; j++)
        cin >> m[i][j];
    }
    for (int j = 1; j < n ; j++)
    {
        for(int i = 1; i < j ;i++)
        {
            m[1][j] = min(m[1][j],m[1][i] + m[1+i][j]);
        }
    }

   /* for(int i = 1; i < n ; i++)
    {
        for (int j = 1 ; j <= n-i ; j++)
        cin >> m[i][j];
    }
    for(int i = 1; i < n ; i++)
    {
        for (int j = 1 ; j < n-i ; j++)                                                
            m[i][n-i+1] = min(m[i][n-i+1],m[i][j] + m[i+j][i-j+1]);
    }*/
    cout << m[1][n-1] << endl;
    return 0;
}
//逻辑出大问题了，循环顺序要换换
 