#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> a;
vector<bool> flag;

void init(int c, int n)
{
    N = n;
    a.assign(n + 1, 0);
    flag.assign(n + 1, 0);
    /*for (int i = 1; i <= n-1; i++)
    {
        a[i] = i + 1;
    }
    a[n] = 1;*/

}

int query(int id)
{
    flag[id] = 1;
    if(id < N) 
    {
        return id + 1;
    }
    while (N >= 1 && flag[N] == 1)
    {
        N--;
    }
    return N + 1; 
}

//////


int main()
{
    const int n = 8;

    vector<int> order(n);
    iota(order.begin(), order.end(), 1);

    int testCount = 0;

    do
    {
        init(0, n);

        vector<int> answer(n + 1, 0);
        vector<int> used(n + 1, 0);

        bool correct = true;
        int oneStep = -1;

        for (int step = 0; step < n; ++step)
        {
            int id = order[step];
            int value = query(id);

            answer[id] = value;

            if (value < 1 || value > n)
            {
                correct = false;
            }
            else
            {
                if (used[value])
                    correct = false;

                used[value] = 1;
            }

            if (value == 1)
                oneStep = step + 1;
        }

        // 检查是否最后一步才返回 1
        if (oneStep != n)
            correct = false;

        // 检查是否为美好序列
        int left = 1;

        while (correct && left <= n)
        {
            int right = left;

            // 一段内部应该满足 answer[i] = i + 1
            while (right < n && answer[right] == right + 1)
                ++right;

            // 一段末尾应该放这一段的最小值 left
            if (answer[right] != left)
            {
                correct = false;
                break;
            }

            left = right + 1;
        }

        cout << "query: ";
        for (int x : order)
            cout << x;

        cout << " -> sequence: ";
        for (int i = 1; i <= n; ++i)
            cout << answer[i];

        cout << (correct ? "  OK" : "  ERROR") << '\n';

        if (!correct)
        {
            cout << "发现错误，停止测试。\n";
            return 1;
        }

        ++testCount;

    } while (next_permutation(order.begin(), order.end()));

    cout << "全部 " << testCount << " 种询问顺序测试通过。\n";
    return 0;
}