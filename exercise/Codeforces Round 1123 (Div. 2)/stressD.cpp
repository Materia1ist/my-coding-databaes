#include <bits/stdc++.h>
using namespace std;

bool isHill(const vector<int> &b)
{
    int n = b.size();
    for (int p = 0; p < n; p++)
    {
        bool ok = true;
        for (int i = 0; i + 1 <= p; i++)
            if (!(b[i] < b[i + 1])) { ok = false; break; }
        if (ok)
            for (int i = p; i + 1 < n; i++)
                if (!(b[i] > b[i + 1])) { ok = false; break; }
        if (ok) return true;
    }
    return false;
}

// 暴力：奇数组、偶数组分别任意排列
bool brute(vector<int> a)
{
    int n = a.size();
    vector<int> O, E;
    for (int i = 0; i < n; i++)
        (i % 2 == 0 ? O : E).push_back(a[i]);
    sort(O.begin(), O.end());
    sort(E.begin(), E.end());
    do
    {
        do
        {
            vector<int> b(n);
            int oi = 0, ei = 0;
            for (int i = 0; i < n; i++)
                b[i] = (i % 2 == 0) ? O[oi++] : E[ei++];
            if (isHill(b)) return true;
        } while (next_permutation(E.begin(), E.end()));
    } while (next_permutation(O.begin(), O.end()));
    return false;
}

bool fast(vector<int> a)
{
    int n = a.size();
    vector<int> pos(n + 1, 0);
    for (int i = 1; i <= n; i++) pos[a[i - 1]] = i;
    vector<int> e(n);
    int c0 = -1;
    for (int v = n, idx = 0; v >= 1; v--)
    {
        if (!pos[v]) continue;
        int cls = pos[v] & 1;
        if (c0 < 0) c0 = cls;
        e[idx++] = cls ^ c0;
    }
    vector<int> pg(n + 1, 0);
    for (int j = 2; j <= n; j++) pg[j] = pg[j - 1] | (e[j - 1] ^ ((j / 2) & 1));
    vector<int> fmin(n + 2, 3), fmax(n + 2, -1);
    for (int j = n; j >= 2; j--)
    {
        int fj = e[j - 1] ^ ((j + 1) & 1);
        fmin[j] = min(fj, fmin[j + 1]);
        fmax[j] = max(fj, fmax[j + 1]);
    }
    for (int m = 0; 2 * m + 1 <= n; m++)
    {
        if (2 * m + 1 >= 2 && pg[2 * m + 1] != 0) continue;
        int s = 2 * m + 2;
        if (s <= n)
        {
            if (fmin[s] != fmax[s]) continue;
            if (fmin[s] != (m & 1)) continue;
        }
        if (n % 2 == 1 && ((m + 1) & 1) != c0) continue;
        return true;
    }
    return false;
}

int main()
{
    mt19937 rng(987654321);
    for (int iter = 0; iter < 30000; iter++)
    {
        int n = 1 + rng() % 8;
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        shuffle(a.begin(), a.end(), rng);
        bool b = brute(a), f = fast(a);
        if (b != f)
        {
            printf("MISMATCH n=%d a= ", n);
            for (int v : a) printf("%d ", v);
            printf("| brute=%d fast=%d\n", (int)b, (int)f);
            return 0;
        }
    }
    printf("all ok\n");
    return 0;
}
