#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int len;
    long long cnt;

    string pre;
    string suf;

    Node(int _len = 0,
         long long _cnt = 0,
         string _pre = "",
         string _suf = "")
        : len(_len), cnt(_cnt), pre(_pre), suf(_suf) {}
};

struct SegTree
{
    int n;
    string s;
    vector<Node> tr;

    SegTree(const string &str)
    {
        s = " " + str; // 1-index
        n = str.size();
        tr.resize(n * 4 + 5);
        build(1, 1, n);
    }

    static Node mergeNode(const Node &L, const Node &R)
    {
        if (L.len == 0)
            return R;
        if (R.len == 0)
            return L;

        Node res;
        res.len = L.len + R.len;

        res.cnt = L.cnt + R.cnt;

        // 统计跨边界 ABC
        string mid = L.suf + R.pre;

        for (int i = 0; i + 2 < (int)mid.size(); i++)
        {
            if (mid[i] == 'A' &&
                mid[i + 1] == 'B' &&
                mid[i + 2] == 'C')
                res.cnt++;
        }

        string tmpPre = L.pre + R.pre;
        if ((int)tmpPre.size() > 2)
            tmpPre.resize(2);
        res.pre = tmpPre;

        string tmpSuf = L.suf + R.suf;
        if ((int)tmpSuf.size() > 2)
            tmpSuf = tmpSuf.substr(tmpSuf.size() - 2);
        res.suf = tmpSuf;

        return res;
    }

    void build(int p, int l, int r)
    {
        if (l == r)
        {
            char c = s[l];

            tr[p].len = 1;
            tr[p].cnt = 0;
            tr[p].pre = string(1, c);
            tr[p].suf = string(1, c);
            return;
        }

        int mid = (l + r) >> 1;

        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);

        tr[p] = mergeNode(tr[p << 1], tr[p << 1 | 1]);
    }

    Node query(int p, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
            return tr[p];

        int mid = (l + r) >> 1;

        if (qr <= mid)
            return query(p << 1, l, mid, ql, qr);

        if (ql > mid)
            return query(p << 1 | 1, mid + 1, r, ql, qr);

        Node L = query(p << 1, l, mid, ql, qr);
        Node R = query(p << 1 | 1, mid + 1, r, ql, qr);

        return mergeNode(L, R);
    }

    Node query(int l, int r)
    {
        return query(1, 1, n, l, r);
    }
};

int main()
{
    freopen("data.in", "r", stdin);
    string s;
    cin >> s;
    SegTree s1(s);
    reverse(s.begin(), s.end());
    SegTree s2(s);
    long long answer = s1.query(1, s1.n).cnt;

    for (int l = 1; l <= s1.n; l++)
    {
        for (int r = l; r <= s1.n; r++)
        {
            Node cur;
            if (l > 1)
                cur = SegTree::mergeNode(
                    cur,
                    s1.query(1, l - 1));

            {
                int L = s1.n - r + 1;
                int R = s1.n - l + 1;

                cur = SegTree::mergeNode(
                    cur,
                    s2.query(L, R));
            }

            if (r < s1.n)
                cur = SegTree::mergeNode(
                    cur,
                    s1.query(r + 1, s1.n));

            answer = min(answer, cur.cnt);
        }
    }

    cout << answer << '\n';
}