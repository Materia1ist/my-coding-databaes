#include <bits/stdc++.h>
using namespace std;

class AVLTree
{
public:
    struct Node
    {
        int key, height, size;
        Node *l, *r, *p;
        Node(int value) : l(nullptr), r(nullptr), p(nullptr), key(value), height(1), size(1) {}
        Node() : l(nullptr), r(nullptr), p(nullptr), key(0), height(1), size(1) {}
    };

    Node *ROOT = nullptr;

    int height(Node *root) const
    {
        return root ? root->height : 0;
    }

    int size(Node *root) const
    {
        return root ? root->size : 0;
    }

    void updateHeight(Node *root)
    {
        if (root)
            root->height = 1 + max(height(root->l), height(root->r));
    }

    void updateSize(Node *root)
    {
        if (root)
            root->size = 1 + size(root->l) + size(root->r);
    }

    int rankBigger(Node *root, int val)
    {
        int rank = 0;
        while (root)
        {
            if (val > root->key)
            {
                rank += size(root->l) + 1;
                root = root->r;
            }
            else
            {
                root = root->l;
            }
        }
        return rank;
    }

    Node *searchMax(Node *root)
    {
        while (root && root->r != nullptr)
        {
            root = root->r;
        }
        return root;
    }

    Node *searchMin(Node *root)
    {
        while (root && root->l != nullptr)
        {
            root = root->l;
        }
        return root;
    }

    Node *findPredecessor(Node *root)
    {
        if (!root)
            return nullptr;
        if (root->l)
            return searchMax(root->l);
        Node *parent = root->p;
        while (parent && root == parent->l)
        {
            root = parent;
            parent = parent->p;
        }
        return parent;
    }

    Node *findSuccessor(Node *root)
    {
        if (!root)
            return nullptr;
        if (root->r)
            return searchMin(root->r);
        Node *parent = root->p;
        while (parent && root == parent->r)
        {
            root = parent;
            parent = parent->p;
        }
        return parent;
    }

    int rank(int val)
    {
        return rankBigger(ROOT, val);
    }

    Node *rotateLeft(Node *root)
    {
        Node *temp = root->r;
        root->r = temp->l;
        if (temp->l)
            temp->l->p = root;
        temp->l = root;
        root->p = temp;

        if (root == ROOT)
        {
            ROOT = temp;
        }

        updateHeight(root);
        updateHeight(temp);
        updateSize(root);
        updateSize(temp);
        return temp;
    }

    Node *rotateRight(Node *root)
    {
        Node *temp = root->l;
        root->l = temp->r;
        if (temp->r)
            temp->r->p = root;
        temp->r = root;
        root->p = temp;

        if (root == ROOT)
        {
            ROOT = temp;
        }

        updateHeight(root);
        updateHeight(temp);
        updateSize(root);
        updateSize(temp);
        return temp;
    }

    Node *balance(Node *root)
    {
        updateHeight(root);
        updateSize(root);

        int diff = height(root->l) - height(root->r);
        if (diff == 2)
        {
            if (height(root->l->r) > height(root->l->l))
            {
                root->l = rotateLeft(root->l);
            }
            return rotateRight(root);
        }
        if (diff == -2)
        {
            if (height(root->r->l) > height(root->r->r))
            {
                root->r = rotateRight(root->r);
            }
            return rotateLeft(root);
        }

        return root;
    }

    Node *insert(Node *root, int val)
    {
        if (!root)
        {
            return new Node(val);
        }
        if (val <= root->key)
        {
            root->l = insert(root->l, val);
            if (root->l)
                root->l->p = root;
        }
        else
        {
            root->r = insert(root->r, val);
            if (root->r)
                root->r->p = root;
        }
        return balance(root);
    }

    Node *remove(Node *root, int val)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (val < root->key)
        {
            root->l = remove(root->l, val);
            if (root->l)
                root->l->p = root;
        }
        else if (val > root->key)
        {
            root->r = remove(root->r, val);
            if (root->r)
                root->r->p = root;
        }
        else
        {
            if (root->l == nullptr && root->r == nullptr)
            {
                delete root;
                return nullptr;
            }
            if (root->l == nullptr)
            {
                Node *temp = root->r;
                temp->p = root->p;
                if (root == ROOT)
                {
                    ROOT = temp;
                }
                delete root;
                return temp;
            }
            if (root->r == nullptr)
            {
                Node *temp = root->l;
                temp->p = root->p;
                if (root == ROOT)
                {
                    ROOT = temp;
                }
                delete root;
                return temp;
            }
            Node *temp = searchMax(root->l);
            root->key = temp->key;
            root->l = remove(root->l, temp->key);
            if (root->l)
                root->l->p = root;
        }
        return balance(root);
    }

    Node *search(Node *root, int val)
    {
        if (!root)
            return nullptr;
        if (root->key == val)
            return root;
        if (val < root->key)
            return search(root->l, val);
        return search(root->r, val);
    }

    Node *searchForPredecessorSuccessor(Node *root, int val)
    {
        Node *result = nullptr;
        while (root)
        {
            result = root;
            if (root->l == nullptr && root->r == nullptr)
            {
                return root;
            }
            if (val < root->key)
            {
                root = root->l;
            }
            else if (val > root->key)
            {
                root = root->r;
            }
            else
            {
                return root;
            }
        }
        return result;
    }

    Node *searchKth(Node *root, int k)
    {
        if (!root)
            return nullptr;
        int leftSize = size(root->l);
        if (k == leftSize + 1)
            return root;
        if (k <= leftSize)
            return searchKth(root->l, k);
        return searchKth(root->r, k - leftSize - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    AVLTree tree;
    int n, m, opt, val, last = 0, ans = 0;
    cin >> n >> m;
    while (n--)
    {
        cin >> val;
        tree.ROOT = tree.insert(tree.ROOT, val);
    }

    while (m--)
    {
        cin >> opt >> val;
        val ^= last;
        if (opt == 1)
        {
            tree.ROOT = tree.insert(tree.ROOT, val);
        }
        if (opt == 2)
        {
            tree.ROOT = tree.remove(tree.ROOT, val);
        }
        if (opt == 3)
        {
            last = tree.rank(val) + 1;
            ans ^= last;
        }
        if (opt == 4)
        {
            AVLTree::Node *result = tree.searchKth(tree.ROOT, val);
            last = (result ? result->key : 0);
            ans ^= last;
        }
        if (opt == 5)
        {
            AVLTree::Node *predecessor = tree.searchForPredecessorSuccessor(tree.ROOT, val);
            while (predecessor->key >= val)
            {
                predecessor = tree.findPredecessor(predecessor);
            }
            last = (predecessor ? predecessor->key : 0);
            ans ^= last;
        }
        if (opt == 6)
        {
            AVLTree::Node *successor = tree.searchForPredecessorSuccessor(tree.ROOT, val);
            while (successor->key <= val)
            {
                successor = tree.findSuccessor(successor);
            }
            
            last = (successor ? successor->key : 0);
            ans ^= last;
        }
    }
    cout << ans << '\n';
    return 0;
}
