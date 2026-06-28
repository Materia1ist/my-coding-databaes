#include <bits/stdc++.h>
#define MAXSIZE 1000005
using namespace std;
int n, q;
int a[MAXSIZE];
unordered_map<int, int> bucket;
multiset<int> frequencies;

int putInBucket()
{
    for (int i = 1; i <= n; i++)
    {
        bucket[a[i]]++;
    }
    for (const auto &pair : bucket)
    {
        frequencies.insert(pair.second);
    }
    return bucket.size();
}

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int kinds = putInBucket(); // kinds num of candy
    int ope, x;
    for (int i = 1; i <= q; i++)
    {
        cin >> ope >> x;
        if (ope == 1)
        {
            if (bucket.find(x) != bucket.end())
            {
                frequencies.erase(frequencies.find(bucket[x]));
            }
            bucket[x]++;
            frequencies.insert(bucket[x]);
        }
        else if (ope == 2)
        {
            frequencies.erase(frequencies.find(bucket[x]));
            bucket[x]--;
            if (bucket[x] == 0)
            {
                bucket.erase(x);
            }
            else
            {
                frequencies.insert(bucket[x]);
            }
        }
        else if (ope == 3)
        {
            // 使用lower_bound找到第一个大于x的频率
            auto it = frequencies.upper_bound(x);
            int ans = 0;
            for (; it != frequencies.end(); ++it)
            {
                ans += *it - x;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
