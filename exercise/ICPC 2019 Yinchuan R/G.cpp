#include <bits/stdc++.h>
using namespace std;

const int prime[4] = {2, 3, 5, 7};
int ban[11][4];
int n, q, root = 0;

struct Node {
    int ls = 0, rs = 0;
    int mx[4]{}, lazy[4]{};
};

vector<Node> t(1);

void init_ban() {
    for (int x = 2; x <= 10; ++x) {
        int v = x;
        for (int k = 0; k < 4; ++k)
            while (v % prime[k] == 0) {
                ++ban[x][k];
                v /= prime[k];
            }
    }
}

int add(int p, int l, int r, int ql, int qr, int x) {
    if (!p) {
        p = (int)t.size();
        t.push_back({});
    }

    if (ql <= l && r <= qr) {
        for (int k = 0; k < 4; ++k) {
            t[p].mx[k] += ban[x][k];
            t[p].lazy[k] += ban[x][k];
        }
        return p;
    }

    int mid = l + (r - l) / 2;
    if (ql <= mid) {
        int child = add(t[p].ls, l, mid, ql, qr, x);
        t[p].ls = child;
    }
    if (qr > mid) {
        int child = add(t[p].rs, mid + 1, r, ql, qr, x);
        t[p].rs = child;
    }

    for (int k = 0; k < 4; ++k)
        t[p].mx[k] = t[p].lazy[k] + max(t[t[p].ls].mx[k], t[t[p].rs].mx[k]);
    return p;
}

int query(int p, int l, int r, int ql, int qr, int k) {
    if (!p || qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return t[p].mx[k];

    int mid = l + (r - l) / 2, ans = 0;
    if (ql <= mid) ans = max(ans, query(t[p].ls, l, mid, ql, qr, k));
    if (qr > mid) ans = max(ans, query(t[p].rs, mid + 1, r, ql, qr, k));
    return t[p].lazy[k] + ans;
}

void mul(int l, int r, int x) {
    root = add(root, 1, n, l, r, x);
}

int get_max(int l, int r) {
    int ans = 0;
    for (int k = 0; k < 4; ++k) ans = max(ans, query(root, 1, n, l, r, k));
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init_ban();
    cin >> n >> q;

    while (q--) {
        string op;
        int l, r;
        cin >> op >> l >> r;
        if (op == "MULTIPLY") {
            int x;
            cin >> x;
            mul(l, r, x);
        } else {
            cout << "ANSWER " << get_max(l, r) << '\n';
        }
    }
}