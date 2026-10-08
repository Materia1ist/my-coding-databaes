#include<bits/stdc++.h>
using namespace std;
int m,n,k;
void opt2() {

    bool useRow = 1LL * (n / 2) * m <= 1LL * n * (m / 2);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (useRow)
                cout << i % 2 << ' ';
            else
                cout << j % 2 << ' ';
        }

        cout << '\n';
    }
}

void opt1()
{
    for (int i = 0; i < n; i++)
    {
        int p = i%2;
        if(p)
        for (int j = 0; j < m; j++)
        {
            cout << (p+1)%2 << ' '; 
            p++;
        }
        else 
        for (int j = 0; j < m; j++)
        {
            cout << "0 "; 
        }
        cout << '\n';
    }
}

void opt3()
{
    for (int i = 1; i <= n; i++)
    {
        int p = i%2;
        if(p)
        for (int j = 0; j < m; j++)
        {
            cout << (p+1)%2 << ' '; 
            p++;
        }
        else 
        for (int j = 0; j < m; j++)
        {
            cout << "1 "; 
        }
        cout << '\n';
    }
}
int main ()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        if(k == 1) opt1();if(k == 2) opt2();if(k == 3) opt3();
    }
    
}