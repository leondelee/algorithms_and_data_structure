#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef vector<string> VEC;
typedef map<int, VEC> MAP;

int my_hash(string str)
{
    unsigned int h = 0;
    for(int i = 0; i < str.size(); i ++) {
        h = (h << 4) + (int) str[i];
        unsigned int g = h & 0xF0000000;
        if(g) h ^= g >> 24;
        h &= ~g;
    }
    return h % INT_MAX;
}

int main()
{
    int T;
    cin >> T;
    for(int t = 0; t < T; t ++) {
        MAP rec;
        VEC res;
        string str;
        cin >> str;
        for(int i = 0; i <= str.size() - 10; i ++) {
            string sub_str = str.substr(i, 10);
            int hv = my_hash(sub_str);
            if(rec.find(hv) == rec.end()) {
                VEC tmp;
                tmp.push_back(sub_str);
                rec[hv] = tmp;
            }
            else {
                if(find(rec[hv].begin(), rec[hv].end(), sub_str) == rec[hv].end()) rec[hv].push_back(sub_str);
                else if(find(res.begin(), res.end(), sub_str) == res.end()) res.push_back(sub_str);
            }
        }
        int len = res.size();
        if(len == 0) cout << "[]" << endl;
        else if(len == 1) cout << '[' << res[0] << ']' << endl;
        else {
            cout << '[' << res[0];
            for(int k = 1; k < len; k ++) cout << ',' << res[k];
            cout << ']' << endl;
        }
    }
    return 0;
}
