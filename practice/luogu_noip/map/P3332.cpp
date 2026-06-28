#include <bits/stdc++.h>
using namespace std;
vector<int> a;

vector<int> get(vector<int> mark)
{
    vector<int> t1,t2,change1,change2;
    t1.push_back(a[mark[0]]);
    t1.push_back(a[mark[1]]);
    t1.push_back(a[mark[2]]);
    t1.push_back(a[mark[3]]);
    sort(t1.begin(),t1.end());
    t2 = t1;
    swap(t2[0],t2[2]);
    swap(t2[1],t2[3]);
    for (int i = 0; i < 4; i++)
    {
        if (t1[i] != a[mark[i]])
        {
            change1.push_back(mark[i]);
        }
        if (t2[i] != a[mark[i]])
        {
            change2.push_back(mark[i]);
        }
    }
    if(change2.size() == 2)
    {
        return change2;
    }
    if (change1.size() == 2)
    {
        return change1;
    }
    
    
    change1.clear();
    return change1;
}

int solve(int gap) // return -1:cant solve,return 1:solve,return 0:dont need to change
{
    int cnt = 0;
    vector<int> mark(4);
    for (int l = 1, r = l + gap; r < a.size(); l += gap * 2, r += gap * 2)
    {
        if (a[l] + gap != a[r])
        {
            cnt++;
            if (cnt == 1)
            {
                mark[0] = l;
                mark[1] = r;
            }
            if (cnt == 2)
            {
                mark[2] = l;
                mark[3] = r;
            }
            if (cnt > 2)
            {
                return -1;
            }
        }
    }
    if (cnt == 0)
        return 0; // case 0
    if (cnt == 1) // case 1 5678 <-> 1234
    {
        for (int i = 0; i < gap; i++)
        {
            swap(a[mark[1] + i], a[mark[2] + i]);
        }
        return 1;
    }
    vector<int> change = get(mark);
    if (change.empty())
    {
        return -1;
    }
    for (int i = 0; i < gap; i++)
    {
        swap(a[change[0] + i], a[change[1] + i]);
    }
    
    return 1;
    // case 3 : 2 1 , 4 3 !!!
    // if (mark[2] + gap == mark[1] && mark[4] + gap == mark[3])
    // {
    //     return -1;
    // }

    // vector<int> temp; // case 2 : 3 6 , 5 4 -> 5 6 , 3 4
    // for (int i = 0; i < gap; i++)
    // {
    //     temp.push_back(a[mark[1] + i]);
    //     temp.push_back(a[mark[2] + i]);
    //     temp.push_back(a[mark[3] + i);
    //     temp.push_back(a[mark[4] + i]);
    // }
    // sort(temp.begin(), temp.end());
    // int p = 0;
    // for (int j = 1; j <= 4; j++)
    // {
    //     for (int i = 0; i < gap; i++)
    //     {
    //         a[mark[j] + i] = temp[p++];
    //     }
    // }
    // return 1;
}
int main()
{
    int n;
    cin >> n;
    a.resize((1 << n) + 1);
    for (int i = 1; i <= 1 << n; i++)
    {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 1; i <= 1 << n; i = i << 1)
    {
        int flag = solve(i);
        if (flag == 1)
        {
            cnt++;
        }
        if (flag == -1)
        {
            cout << 0;
            return 0;
        }
    }
    int ans = 1;
    while (cnt)
    {
        ans *= cnt;
        cnt--;
    }
    cout << ans;
    return 0;
}