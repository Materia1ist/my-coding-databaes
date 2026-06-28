#include <bits/stdc++.h>
using namespace std;

static inline int isABC(char a, char b, char c) {
    return (a == 'A' && b == 'B' && c == 'C');
}

int main() {
    freopen("data.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n = S.size();
    S = " " + S;

    // 预处理原答案
    long long base = 0;
    for (int i = 1; i + 2 <= n; i++) {
        if (isABC(S[i], S[i+1], S[i+2])) base++;
    }

    long long ans = base;

    // reverse字符串（用于快速取 reverse(B)）
    string R = S;
    reverse(R.begin() + 1, R.end());

    /*
        B = [l, r]
        reverse(B) = R[n-r+1 .. n-l+1]
    */

    for (int r = 1; r <= n; r++) {

        string B_rev = ""; // dynamic reverse segment (we rebuild incrementally via l)

        for (int l = r; l >= 1; l--) {

            // 构造 B = S[l..r]
            // reverse(B) = R[n-r+1 .. n-l+1]

            int Lr = n - r + 1;
            int Rr = n - l + 1;

            // ---- 1. 计算翻转后内部 ABC ----
            long long inside_rev = 0;
            for (int i = Lr; i + 2 <= Rr; i++) {
                if (isABC(R[i], R[i+1], R[i+2]))
                    inside_rev++;
            }

            long long inside_ori = 0;
            for (int i = l; i + 2 <= r; i++) {
                if (isABC(S[i], S[i+1], S[i+2]))
                    inside_ori++;
            }

            long long delta = inside_rev - inside_ori;

            // ---- 2. 边界贡献（暴力窗口但常数） ----

            // 左边界 A + B
            if (l > 1) {
                int al = max(1, l - 2);
                int ar = l - 1;
                string A = S.substr(al, ar - al + 1);

                string Bpre = "";
                for (int i = Lr; i <= min(Lr + 1, Rr); i++)
                    Bpre.push_back(R[i]);

                string mid = A.substr(max(0, (int)A.size() - 2)) + Bpre;

                for (int i = 0; i + 2 < (int)mid.size(); i++) {
                    if (isABC(mid[i], mid[i+1], mid[i+2]))
                        delta++;
                }

                // 原边界（不翻转）
                string Bori_pre = S.substr(l, min(2, r - l + 1));
                string mid2 = A.substr(max(0, (int)A.size() - 2)) + Bori_pre;

                for (int i = 0; i + 2 < (int)mid2.size(); i++) {
                    if (isABC(mid2[i], mid2[i+1], mid2[i+2]))
                        delta--;
                }
            }

            // 右边界 B + C
            if (r < n) {
                int cl = r + 1;
                int cr = min(n, r + 2);
                string C = S.substr(cl, cr - cl + 1);

                string Bsuf = "";
                for (int i = max(Lr, Rr - 1); i <= Rr; i++)
                    Bsuf.push_back(R[i]);

                string mid = Bsuf + C.substr(0, min(2, (int)C.size()));

                for (int i = 0; i + 2 < (int)mid.size(); i++) {
                    if (isABC(mid[i], mid[i+1], mid[i+2]))
                        delta++;
                }

                // 原边界
                string Bori_suf = S.substr(max(l, r - 1), min(2, r - l + 1));
                string mid2 = Bori_suf + C.substr(0, min(2, (int)C.size()));

                for (int i = 0; i + 2 < (int)mid2.size(); i++) {
                    if (isABC(mid2[i], mid2[i+1], mid2[i+2]))
                        delta--;
                }
            }

            ans = min(ans, base + delta);
        }
    }

    cout << ans << "\n";
    return 0;
}