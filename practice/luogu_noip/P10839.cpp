#include <bits/stdc++.h>
using namespace std;
int opt(int a, int b, int op)
{
    if (op == 1)
        return a + b;
    if (op == 2)
        return a - b;
    if (op == 3)
        return a * b;
    if (op == 4)
        return a / b;
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = 1; i <= 4; i++)
    {
        int temp = opt(a,b,i);
        for (int j = 1; j <= 4; j++)
        {
            if (opt(temp, c, j) == d)
            {
                cout << "Yes";
                return 0;
            }
            
        }
        
    }
    cout<<"No";
}