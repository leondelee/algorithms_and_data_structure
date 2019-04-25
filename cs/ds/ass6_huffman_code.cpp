#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

class TreeNode
{
public:
    int wgt;
    char ch;
    TreeNode *lc;
    TreeNode *rc;
    TreeNode()
    {
        lc = rc = NULL;
    }

    TreeNode(int weight, char character)
    {
        lc = rc = NULL;
        wgt = weight;
        ch = character;
    }
};
typedef vector<TreeNode*> vec;
template<class T>
bool my_comp(T x, T y)
{
    return x ->wgt > y ->wgt;
}

class HuffmanTree
{
private:
    TreeNode *root_;
    string str_;

    void build_tree()
    {
        vec t_vec;
        for(map<char, int>::const_iterator it = fre_map_.begin(); it != fre_map_.end(); it ++) {
            TreeNode *tmp = new TreeNode(it ->second, it ->first);
            t_vec.push_back(tmp);
        }
        while(t_vec.size() != 1) {
            sort(t_vec.begin(), t_vec.end(), my_comp<TreeNode*>);
            TreeNode *t1 = t_vec.back();
            t_vec.pop_back();
            TreeNode *t2 = t_vec.back();
            t_vec.pop_back();
            TreeNode *t = new TreeNode();
            t ->lc = t1; t ->rc = t2;
            t ->wgt = t1 ->wgt + t2 ->wgt;
            t_vec.push_back(t);
        }
        root_ = t_vec.back();
        t_vec.clear();
    }

    void trav_helper(TreeNode *r, string& code)
    {
        if(! r) return;
        code.push_back('0');
        trav_helper(r ->lc, code);
        code.erase(code.end() - 1);
        if(! r ->lc && ! r ->rc) code_[r ->ch] = code;
        code.push_back('1');
        trav_helper(r ->rc, code);
        code.erase(code.end() - 1);
    }

public:
    map<char, int> fre_map_;
    map<char, string> code_;

    HuffmanTree(string str)
    {
        str_ = str;
        for(int i = 0; i < str.size(); i ++) {
            char ch = str[i];
            if(fre_map_.find(ch) != fre_map_.end()) fre_map_[ch] ++;
            else fre_map_[ch] = 1;
        }
        build_tree();
    }

    void trav()
    {
        string code = "";
        trav_helper(root_, code);
    }
};

int main()
{
    string str;
    while(cin >> str) {
        if(str == "END") break;
        if(! str.size()) continue;
        HuffmanTree ht(str);
        ht.trav();
        float ascii_len = 8 * str.size();
        float huffman_len = 0;
        for(map<char, string>::const_iterator it = ht.code_.begin(); it != ht.code_.end(); it ++) {
            char ch = it ->first;
            huffman_len += (it ->second).size() * ht.fre_map_[ch];
        }
        cout << (int) ascii_len << " " << (int) huffman_len << " " << setprecision(2) << ascii_len / huffman_len << endl;
    }
    return 0;
}
