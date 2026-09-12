#include <bits/stdc++.h>
using namespace std;
#define ll __int128_t

inline void read(ll &n){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    n=x*f;
}

inline void print(ll n){
    if(n<0){
        putchar('-');
        n*=-1;
    }
    if(n>9) print(n/10);
    putchar(n % 10 + '0');
}
#undef int


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        read(n);
        read(k);

        if (n == 1)//sp1
        {
            cout << "-1\n";
            continue;
        }

        n *= k;
        if (n % 2)
        {
            print(n/2);
            cout  << ".50\n";
        }
        else
        {
            print(n/2);
            cout << ".00\n";
        }
    }
}