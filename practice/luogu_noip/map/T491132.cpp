#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
map<pair<int,int>,int> fac;

long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void inline get_factors(int n) {
    int sqrt_n = sqrt(n);

    for (int i = 2; i <= sqrt_n; ++i) {
        if (n % i == 0) {
            for (int m = i; m <= 200000; m += i)
            {
                int x = m^n;
                if (x > n)
                {
                    return;
                }
                if(x)
                {
                    fac[{n,x}] = i; 
                }
            }
        }
    }
    return;
}



int main() {
    int T;
    cin >> T;
    for (int i = 1; i < 200000; i++)
    {
        get_factors(i);
    }
    cout<<fac.size();
    while (T--) {
        int n, k,ans;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i; i++)
            {
                if (fac[{j,i}])
                {
                    ans += modPow([{j,i}])
                }
                else
                {
                    ans += 1;
                }
            }
            ans+=i;
            ans%=MOD;
        }
        
    }

    return 0;
}
