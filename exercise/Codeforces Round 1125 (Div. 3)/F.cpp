#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1000001;
const int N = 1e6 + 5;
vector<int> prime;
bool isPrime[N + 5];
unordered_map<int, int> bak;
void Erato()
{
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= N; i++)
        isPrime[i] = 1;
    for (int i = 2; i <= N; i++)
    {
        if (isPrime[i])
        {
            prime.push_back(i);
            if (i * i > N)
                continue;
            for (int j = i * i; j <= N; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
}
// bitset<M> sum;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    Erato();
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        bak.clear();
        // sum.reset();
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            a[i] = temp;
            int mul = 1;
            for (auto p : prime)
            {
                if (p * p > temp)
                    break;
                if (temp % p)
                    continue;
                int c = 0;
                while (temp % p == 0)
                {
                    temp /= p;
                    c ^= 1;
                }
                if (c)
                    mul *= p;
            }
            if (temp > 1)
                mul *= temp;
            bak[mul]++;
        }
        int ans = 0;
        set<int> sum;
        for (int i = 0; i < n; i++)
        {
            int temp = a[i];
            for (auto p : prime)
            {
                if (p * p > temp)
                    break;
                if (temp % p)
                    continue;
                int c = 0;
                while (temp % p == 0)
                {
                    temp /= p;
                    c ^= 1;
                }
                if (c)
                {
                    if (sum.count(p))
                        sum.erase(p);
                    else
                        sum.insert(p);
                }
            }
            if (temp > 1)
            {
                if (sum.count(temp))
                    sum.erase(temp);
                else
                    sum.insert(temp);
            }
            int q = 1;
            for (auto p : sum)
            {
                q *= p;
                if (q > 1000000)
                    break;
            }
            if (q <= 1000000)
                ans += bak[q];
        }
        cout << ans << endl;
    }
}
