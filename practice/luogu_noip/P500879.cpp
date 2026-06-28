#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    set<tuple<int, int, int>> triples;
    vector<tuple<int, int, int>> triplets(m);

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        triples.insert({u, v, w});
        triplets[i] = {u, v, w};
    }

    int result = 0;
    for (const auto &[u, v, w] : triplets)
    {
        for (int d = w + 1; d <= n; ++d)
        {
            if (triples.count({u, v, d}) && triples.count({u, w, d}) && triples.count({v, w, d}))
            {
                result++;
            }
        }
    }

    cout << result << endl;
    return 0;
}
