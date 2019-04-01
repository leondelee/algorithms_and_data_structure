#include <iostream>
#include <string>
using namespace std;

void print_post_order(string& pre, string& in, int preS, int preE, int inS, int inE)
{
    if(preS > preE || inS > inE) return;
    char root = pre[preS];
    int cur;
    for(cur = inS; cur <= inE; cur ++)
        if(in[cur] == root)
            break;
    print_post_order(pre, in, preS + 1, preS + cur - inS, inS, cur - 1);
    print_post_order(pre, in, preS + cur + 1 - inS, preE, cur + 1, inE);
    cout << root;
}

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; i ++) {
        string pre, in;
        cin >> pre >> in;
        int e = pre.size() - 1;
        print_post_order(pre, in, 0, e, 0, e);
        cout << endl;
    }
    return 0;
}
