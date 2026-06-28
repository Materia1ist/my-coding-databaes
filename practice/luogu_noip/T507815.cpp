#include <bits/stdc++.h>
using namespace std;
#define int long long

// signed main ()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int a;
//         cin >> a;
//         if(a * 3 < 1634826193)
//         cout << 1 << " " << a * 2 << " " << a * 3 << endl;
//         else
//         cout << 1 << " " << a * 4 / 5 << " " << a * 3 / 5 << endl;
//     }

// }
// 计算 gcd
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// 计算 lcm
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a;
        cin >> a;

        bool found = false;

        // 暴力枚举 b, c, d
        for (int b = 1; b <= 10000000; ++b)
        {
            for (int c = 1; c <= a; ++c)
            {
                for (int d = 1; d <= a; ++d)
                {
                    if (a + b + c + d == gcd(a, b) + lcm(c, d))
                    {
                        // 输出满足条件的 b, c, d
                        cout << b << " " << c << " " << d << endl;
                        // found = true;
                        break;
                    }
                }
                if (found)
                    break;
            }
            if (found)
                break;
        }
    }

    return 0;
}
