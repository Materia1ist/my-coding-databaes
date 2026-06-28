#include <bits/stdc++.h>
#define red 0
#define black 1
using namespace std;

class RBTree
{
public:
    struct nobe
    {
        bool col;
        int n, bh, size;
        nobe *p;
        nobe *l;
        nobe *r;
        nobe(nobe *parent, nobe *left, nobe *right, int value, bool color,int s) : p(parent), l(left), r(right), n(value), col(color) ,size(s){}
        nobe(int value) : p(nullptr), l(nullptr), r(nullptr), n(value), col(black), size(1) {}
        nobe() : p(nullptr), l(nullptr), r(nullptr), n(0), col(black), size(1) {}
    };
    
    nobe *key;
    int size = 0;

    void leftRotate(nobe *root)
    {
        nobe *r = root->r;
        r->p = root->p;
        root->p = r;
        r->l->p = root;
        r->l = root;
        root->r = r->l;
    }

    void rightRotate(nobe *root)
    {
        nobe *l = root->l;
        l->p = root->p;
        root->p = l;
        l->r->p = root;
        l->r = root;
        root->l = l->r;
    }

    nobe *findMax(nobe *root)
    {
        while (root->r != nullptr)
        {
            root = root->r;
        }
        return root;
    }

    nobe *findMin(nobe *root)
    {
        while (root->l != nullptr)
        {
            root = root->l;
        }
        return root;
    }

    nobe *search(nobe *root, int val)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->n == val)
        {
            return root;
        }
        if (root->n < val)
        {
            return search(root->r, val);
        }
        return search(root->l, val);
    }

    nobe *insert(nobe *root, int val)
    {
        if (root == nullptr)
        {
            size++;
            nobe *newNode = new nobe(val);
            if (size == 1)
            {
                key = newNode;
            }
            return newNode;
        }
        if (val <= root->n)
        {
            root->l = insert(root->l, val);
            root->size++;
            root->l->p = root;
        }
        else
        {
            root->r = insert(root->r, val);
            root->size++;
            root->r->p = root;
        }
        return root;
    }

    nobe* remove(nobe *root, int val)
    {
        if (root == nullptr)
            return root;

        // Node to be deleted is found
        if (val < root->n)
        {
            root->l = remove(root->l, val);
            root->size--;
        }
        else if (val > root->n)
        {
            root->r = remove(root->r, val);
            root->size--;
        }
        else
        {
            // Node with only one child or no child
            if (root->l == nullptr)
            {
                nobe *temp = root->r;
                if (root == key) key = temp;
                delete root;
                nobe *t = temp;
                size--;
                return temp;
            }
            else if (root->r == nullptr)
            {
                nobe *temp = root->l;
                if (root == key) key = temp;
                delete root;
                size--;
                return temp;
            }

            // Node with two children: Get the inorder predecessor (max in the left subtree)
            nobe *temp = findMax(root->l);
            root->n = temp->n;
            root->l = remove(root->l, temp->n);
        }
        return root;
    }

    int queryRank(int n, nobe *root)
    {

    }

    void inOrder(nobe *p)
    {
        if (p == nullptr)
            return;
        inOrder(p->l);
        printf("%d ", p->n);
        inOrder(p->r);
    }
};

int main()
{
    using namespace std::chrono;

    RBTree tree;
    RBTree::nobe *root = nullptr;

    vector<int> test_values;

    // 生成对抗性样例，形成链表结构
    for (int i = 0; i < 10000; ++i)
    {
        test_values.push_back(i);
    }

    // 插入节点并计时
    auto start = high_resolution_clock::now();
    for (int val : test_values)
    {
        root = tree.insert(root, val);
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Time taken to insert 10000 nodes (sequential): " << duration.count() << " ms" << endl;

    // 删除节点并计时
    start = high_resolution_clock::now();
    for (int val : test_values)
    {
        root = tree.remove(root, val); //更新节点
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "Time taken to remove 10000 nodes (sequential): " << duration.count() << " ms" << endl;

    // 清空树并重新生成根节点
    root = nullptr;
    tree = RBTree();

    // 生成对抗性样例，形成混合结构
    test_values.clear();
    for (int i = 0; i < 10000; ++i)
    {
        test_values.push_back(i);
    }
    random_shuffle(test_values.begin(), test_values.end());

    // 插入节点并计时
    start = high_resolution_clock::now();
    for (int val : test_values)
    {
        root = tree.insert(root, val);
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "Time taken to insert 10000 nodes (random): " << duration.count() << " ms" << endl;

    // 删除节点并计时
    random_shuffle(test_values.begin(), test_values.end());
    start = high_resolution_clock::now();
    for (int val : test_values)
    {
        root = tree.remove(root, val);
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "Time taken to remove 10000 nodes (random): " << duration.count() << " ms" << endl;

    return 0;
}
