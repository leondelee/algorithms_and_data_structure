#include <iostream>
#include <vector>
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

    void insert_help(BSTNode *r, int v)
    {
        if(! root) {
            root = new BSTNode(v);
            return;
        }
        if(v >= r ->val) {
            if(! r ->rc) r ->rc = new BSTNode(v);
            else insert_help(r ->rc, v);
        }
        else {
            if(! r ->lc) r ->lc = new BSTNode(v);
            else insert_help(r ->lc, v);
        }
    }

    void find_help(BSTNode *r, vector<int>& rest, BSTNode*& res)
    {
        if(! r) return;
        int pre_len = rest.size();
        if(! pre_len) return;
        find_help(r ->lc, rest, res);
        if(pre_len - rest.size() == 2) {
             if(res == NULL) res = r;
             return;
        }
        for(int i = 0; i < rest.size(); i ++) {
            if(r ->val == rest[i]) {
                int l = rest.size();
                rest.erase(rest.begin() + i);
            }

        }
        if(pre_len - rest.size() == 2)  {
            if(res == NULL) res = r;
            return;
        }
        if(! rest.size()) return;
        find_help(r ->rc, rest, res);
        if(pre_len - rest.size() == 2)  {
            if(res == NULL) res = r;
            return;
        }
    }
public:
    BST()
    {
        root = NULL;
    }

    void insert(int v)
    {
        insert_help(root, v);
    }

    int find(int x, int y)
    {
        vector<int> rest;
        rest.push_back(x);
        rest.push_back(y);
        BSTNode *res = NULL;
        find_help(root, rest, res);
        return res ->val;
    }

    void show()
    {
        show_help(root);
        cout << endl;
    }
};

int main()
{
    int T;
    cin >> T;
    for(int t = 0; t < T; t ++) {
        int len, x, y;
        cin >> len;
        BST bst;
        for(int i = 0; i < len; i ++) {
            int dig;
            cin >> dig;
            bst.insert(dig);
        }
        cin >> x >> y;
        cout << bst.find(x, y) << endl;
    }
    return 0;
}

