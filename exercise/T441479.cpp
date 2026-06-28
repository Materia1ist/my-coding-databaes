#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long> a;
    freopen("numlist.txt", "r", stdin);
    freopen("numlist.ans", "w", stdout);
    int i = 0;
    long long ans;
    do
    {
        cin >> i;
        a.push_back(i);
    } while (getchar() != '\n');
    for (int j = 0; j < a.size(); j++)
    {
        while (a[j] % 2 == 0)
        {
            ans++;
            a[j] /= 2;
            //   printf(".");
        }
    }

    printf("%lld", ans);

    return 0;
}