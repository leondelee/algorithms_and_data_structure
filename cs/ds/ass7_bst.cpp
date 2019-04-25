#include <iostream>
using namespace std;

class BSTNode
{
public:
    int val;
    BSTNode *lc, *rc;
    BSTNode(int v)
    {
        val = v;
        lc = rc = NULL;
    }
};

class BST
{
private:
    BSTNode *root;

    void show_help(BSTNode *r)
    {
        if(! r) return;
        show_help(r ->lc);
        cout << r ->val << " ";
        show_help(r ->rc);
    }

    bool is_leaf(BSTNode *r)
    {
        return ((! r ->lc) && (! r ->rc));
    }

    void insert_help(BSTNode *r, int v)
    {
        if(! root) {
            root = new BSTNode(v);
            return;
        }
        if(is_leaf(r)) {
            if(v >= r ->val) r ->rc = new BSTNode(v);
            else r ->lc = new BSTNode(v);
            return;
        }
        if(v >= r ->val) insert_help(r ->rc, v);
        else insert_help(r ->lc, v);
    }
public:
    BST()
    {
        root = NULL;
    }

    insert(int v)
    {
        insert_help(root, v);
    }

    void show()
    {
        show_help(root);
    }
};

int main()
{
    int T;
    cin >> T;
    for(int t = 0; t < T; t ++) {
        int len;
        cin >> len;
        BST bst;
        for(int i = 0; i < len; i ++) {
            int dig;
            cin >> dig;
            bst.insert(dig);
        }
        bst.show();
    }
    return 0;
}
