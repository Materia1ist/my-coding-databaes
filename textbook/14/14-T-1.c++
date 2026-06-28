#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if(i==n)
        {
            for (int j = 1; j < 2*n; j++)
            {
                cout<<"*";
            }
            
        }
        else
        {
            for (int j = 1; j <= n-i; j++)
            {
                cout << " ";
            }
            cout<<"*";
            for (int j = 1; j < i*2-2; j++)
            {
                cout << " ";
            }
            if(i!=1){cout<<"*";}
        }

        cout<<endl;
    }
}