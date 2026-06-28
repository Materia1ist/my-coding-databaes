#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val, rank, size, repCnt;
    Node *l;
    Node *r;
    Node(int v) : val(v), repCnt(1), size(1)
    {
        l = r = nullptr;
        rank = rand();
    }
    void resize()
    {
        size = (l ? l->size : 0) + (r ? r->size : 0) + repCnt;
    }
};
Node *Root;
pair<Node *, Node *> split(int val, Node *root)
{
    if (root == nullptr)
    {
        return {nullptr, nullptr};
    }
    if (root->val <= val)
    {
        auto temp = split(val, root->r);
        root->r = temp.first;
        root->resize();
        return {root, temp.second};
    }
    else
    {
        auto temp = split(val, root->l);
        root->l = temp.second;
        root->resize();
        return {temp.first, root};
    }
}
tuple<Node*,Node*,Node*> splitByRk(Node * root, int rk)
{
    if (root == nullptr)
    {
        return {nullptr,nullptr,nullptr};
    }
    int lsize = root->l == nullptr ? 0 : root->l->size;
    if (rk <= lsize)
    {
        Node *l,*m,*r;
        tie(l,m,r) = splitByRk(root->l ,rk);
        root->l = r;
        root->resize();
        return{l,m,root};
    }
    else if (rk <= lsize + root->repCnt)
    {
        Node *l = root->l,*r = root->r;
        root->r = root->l = nullptr;
        root->resize();
        return {l,root,r};
    }
    else
    {
        Node *l,*m,*r;
        tie(l,m,r) = splitByRk(root->r ,rk - root->repCnt - lsize);
        root->r=l;
        root->resize();
        return {root,m,r};
    }
    
    
    
    
    
}
Node *merge(Node *u, Node *v) // A val u < v
{
    if (u == nullptr && v == nullptr)
    {
        return nullptr;
    }
    if (v == nullptr)
    {
        return u;
    }
    if (u == nullptr)
    {
        return v;
    }
    if (u->rank < v->rank)
    {
        u->r = merge(u->r, v);
        u->resize();
        return u;
    }
    else
    {
        v->l = merge(u,v->l);
        v->resize();
        return v;
    }
}
void insert(int val)
{
    auto temp = split(val, Root);
    auto l_tr = split(val - 1, temp.first);
    Node *newNode;
    if (l_tr.second == nullptr)
    { 
        newNode = new Node(val);
    }
    else
    {
        l_tr.second->repCnt++;
        l_tr.second->resize();
    }
    Node *l_tr_combined =
      merge(l_tr.first, l_tr.second == nullptr ? newNode : l_tr.second);
    Root = merge(l_tr_combined, temp.second);
}
void del(int val)
{
    auto temp = split(val, Root);
    auto l_tr = split(val - 1, temp.first);

    // 如果 l_tr.second 为空，说明要删除的值不存在
    if (l_tr.second == nullptr)
    {
        Root = merge(l_tr.first, temp.second); // 合并并返回
        return;
    }

    if (l_tr.second->repCnt > 1)
    {
        l_tr.second->repCnt--;
        l_tr.second->resize();
        temp.first = merge(l_tr.first, l_tr.second);
    }
    else
    {
        delete l_tr.second; // 删除节点
        l_tr.second = nullptr;
        temp.first = merge(l_tr.first, l_tr.second); // 合并剩余部分
    }

    Root = merge(temp.first, temp.second);
}
int getrank(int val)
{
    auto temp = split(val-1,Root);
    int ans = (temp.first == nullptr ? 0 : temp.first->size) + 1;
    Root = merge(temp.first,temp.second);
    return ans;
}



int searchKth(int kth)
{
    Node *l,*m,*r;
    tie(l,m,r) = splitByRk(Root,kth);
    int ans = m->val;
    Root = merge(merge(l,m),r);
    return ans;
}

void printTree(Node* root, string indent = "") {
    if (root == nullptr) return;
    
    // 打印当前节点的值、rank、size、repCnt
    cout << indent << "Node: " << root->val 
         << ", Rank: " << root->rank 
         << ", Size: " << root->size 
         << ", RepCnt: " << root->repCnt;

    // 打印左孩子和右孩子的值（如果有）
    if (root->l) {
        cout << ", Left Child: " << root->l->val;
    } else {
        cout << ", Left Child: null";
    }
    
    if (root->r) {
        cout << ", Right Child: " << root->r->val;
    } else {
        cout << ", Right Child: null";
    }
    
    cout << endl;

    // 递归打印左子树和右子树
    printTree(root->l, indent + "  ");
    printTree(root->r, indent + "  ");
}

int main()
{
    // 初始化随机数种子
    srand(time(nullptr));
    int n,m;
    cin>>n>>m;
    int a[n+1], u[m+1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i];
    }
    for (int i = 1,p = 1,k = 1; i <= n; i++)
    {
        insert(a[i]);
        while (u[p] == i)
        {
            cout<<searchKth(k)<<endl;
            p++;
            k++;
        }
    }
    
    
    return 0;
}

