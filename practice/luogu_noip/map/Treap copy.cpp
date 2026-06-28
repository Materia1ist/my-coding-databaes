#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node *ch[2];
  int val, prio;
  int cnt;
  int siz;

  Node(int _val) : val(_val), cnt(1), siz(1) {
    ch[0] = ch[1] = nullptr;
    prio = rand();
  }

  Node(Node *_node) {
    val = _node->val, prio = _node->prio, cnt = _node->cnt, siz = _node->siz;
  }

  void upd_siz() {
    siz = cnt;
    if (ch[0] != nullptr) siz += ch[0]->siz;
    if (ch[1] != nullptr) siz += ch[1]->siz;
  }
};

struct none_rot_treap {
#define _3 second.second
#define _2 second.first
  Node *root;

  pair<Node *, Node *> split(Node *cur, int key) {
    if (cur == nullptr) return {nullptr, nullptr};
    if (cur->val <= key) {
      auto temp = split(cur->ch[1], key);
      cur->ch[1] = temp.first;
      cur->upd_siz();
      return {cur, temp.second};
    } else {
      auto temp = split(cur->ch[0], key);
      cur->ch[0] = temp.second;
      cur->upd_siz();
      return {temp.first, cur};
    }
  }

  tuple<Node *, Node *, Node *> split_by_rk(Node *cur, int rk) {
    if (cur == nullptr) return {nullptr, nullptr, nullptr};
    int ls_siz = cur->ch[0] == nullptr ? 0 : cur->ch[0]->siz;
    if (rk <= ls_siz) {
      Node *l, *mid, *r;
      tie(l, mid, r) = split_by_rk(cur->ch[0], rk);
      cur->ch[0] = r;
      cur->upd_siz();
      return {l, mid, cur};
    } else if (rk <= ls_siz + cur->cnt) {
      Node *lt = cur->ch[0];
      Node *rt = cur->ch[1];
      cur->ch[0] = cur->ch[1] = nullptr;
      return {lt, cur, rt};
    } else {
      Node *l, *mid, *r;
      tie(l, mid, r) = split_by_rk(cur->ch[1], rk - ls_siz - cur->cnt);
      cur->ch[1] = l;
      cur->upd_siz();
      return {cur, mid, r};
    }
  }

  Node *merge(Node *u, Node *v) {
    if (u == nullptr && v == nullptr) return nullptr;
    if (u != nullptr && v == nullptr) return u;
    if (v != nullptr && u == nullptr) return v;
    if (u->prio < v->prio) {
      u->ch[1] = merge(u->ch[1], v);
      u->upd_siz();
      return u;
    } else {
      v->ch[0] = merge(u, v->ch[0]);
      v->upd_siz();
      return v;
    }
  }

  void insert(int val) {
    auto temp = split(root, val);
    auto l_tr = split(temp.first, val - 1);
    Node *new_node;
    if (l_tr.second == nullptr) {
      new_node = new Node(val);
    } else {
      l_tr.second->cnt++;
      l_tr.second->upd_siz();
    }
    Node *l_tr_combined =
        merge(l_tr.first, l_tr.second == nullptr ? new_node : l_tr.second);
    root = merge(l_tr_combined, temp.second);
  }

  void del(int val) {
    auto temp = split(root, val);
    auto l_tr = split(temp.first, val - 1);
    if (l_tr.second->cnt > 1) {
      l_tr.second->cnt--;
      l_tr.second->upd_siz();
      l_tr.first = merge(l_tr.first, l_tr.second);
    } else {
      if (temp.first == l_tr.second) {
        temp.first = nullptr;
      }
      delete l_tr.second;
      l_tr.second = nullptr;
    }
    root = merge(l_tr.first, temp.second);
  }

  int qrank_by_val(Node *cur, int val) {
    auto temp = split(cur, val - 1);
    int ret = (temp.first == nullptr ? 0 : temp.first->siz) + 1;
    root = merge(temp.first, temp.second);
    return ret;
  }

  int qval_by_rank(Node *cur, int rk) {
    Node *l, *mid, *r;
    tie(l, mid, r) = split_by_rk(cur, rk);
    int ret = mid->val;
    root = merge(merge(l, mid), r);
    return ret;
  }

  int qprev(int val) {
    auto temp = split(root, val - 1);
    int ret = qval_by_rank(temp.first, temp.first->siz);
    root = merge(temp.first, temp.second);
    return ret;
  }

  int qnex(int val) {
    auto temp = split(root, val);
    int ret = qval_by_rank(temp.second, 1);
    root = merge(temp.first, temp.second);
    return ret;
  }
};

none_rot_treap tr;

// 打印树结构的调试函数
void printTree(Node* node, const std::string& prefix = "", bool isLeft = true) {
    if (node != nullptr) {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──");

        // 输出节点的详细信息
        std::cout << " val: " << node->val 
                  << ", prio: " << node->prio 
                  << ", cnt: " << node->cnt 
                  << ", siz: " << node->siz;
        if (node->ch[0] != nullptr) 
            std::cout << ", left: " << node->ch[0]->val;
        else 
            std::cout << ", left: nullptr";
        if (node->ch[1] != nullptr) 
            std::cout << ", right: " << node->ch[1]->val;
        else 
            std::cout << ", right: nullptr";
        std::cout << std::endl;

        // 递归打印左子树和右子树
        printTree(node->ch[0], prefix + (isLeft ? "│   " : "    "), true);
        printTree(node->ch[1], prefix + (isLeft ? "│   " : "    "), false);
    }
}
#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;
int n, k, a[12], b[12], ans[12], fa[12];

// 查找并查集的根节点
int findfa(int u) { 
    return u == fa[u] ? u : fa[u] = findfa(fa[u]); 
}

// 生成下一个字典序排列
int functionUnknown(int a[], int n) {
    if (n <= 1) return 0;
    int i = n - 1, j, k;
    while (true) {
        j = i; 
        --i;
        if (a[i] < a[j]) {
            for (k = n; a[i] >= a[--k];);
            swap(a[i], a[k]);
            reverse(a + j, a + n);
            return 1;
        }
        if (!i) {
            reverse(a, a + n);
            return 0;
        }
    }
    return -1;
}

// 多项式计算
int F(int x) {
    int ans = 0;
    for (int i = k - 1; ~i; --i)
        ans = (1ll * ans * x % mod + a[i]) % mod;
    return ans;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; ++i) scanf("%d", a + i);

    for (int m = 1; m <= n; ++m) {
        for (int i = 0; i < m; ++i) b[i] = i;
        do {
            for (int i = 0; i < m; ++i) fa[i] = i;
            int res = m;
            for (int i = 0, u, v; i < m; ++i) {
                u = findfa(i); 
                v = findfa(b[i]);
                if (u == v) continue;
                --res; 
                fa[u] = v;
            }
            int flag = 0;
            for (int i = 0; i < m; ++i)
                if (b[i] == i) flag = 1;
            if (flag) continue;
            ans[m] = (ans[m] + F(res)) % mod;
        } while(functionUnknown(b, m));
        printf("%d%c", ans[m], " \n"[m == n]);
    }
    return 0;
}
