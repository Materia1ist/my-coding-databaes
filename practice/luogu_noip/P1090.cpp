#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;

priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
    ll n, a, sum = 0;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a);
        pq.push(a);
    }

    while (pq.size() > 1) {
        ll n1 = pq.top(); pq.pop();
        ll n2 = pq.top(); pq.pop();
        sum += n1 + n2;
        pq.push(n1 + n2);
    }

    printf("%lld", sum);

    return 0;
}
