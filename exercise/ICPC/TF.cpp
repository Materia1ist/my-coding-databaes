#include<bits/stdc++.h>
using namespace std;

inline __int128 read() {
    char ch = getchar();
    __int128 X = 0;
    int w = 1;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        X = X * 10 + (ch - '0');
        ch = getchar();
    }
    return X * w;
}

inline void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        print(x / 10);
    }
    putchar(x % 10 + '0');
}

int main()
{
    __int128_t a = 1,b = 2,c = 0;
    vector<__int128> ans;
    ans.push_back(b * 2);
    for(int i = 0 ; i < 65 ; i++)
    {
        c = 4 * b - a;
        a = b;
        b = c;
        ans.push_back(c* 2);
    }
    int t;
    cin >> t;
    for(int i = 0 ; i < t ; i++)
    {
        __int128_t n = read();
        for(int j = 0 ; j < ans.size() ; j++)
        {
            if(ans[j] >= n)
            {
                print(ans[j]);
                break;
            }
        }
        cout << endl;
    }
}