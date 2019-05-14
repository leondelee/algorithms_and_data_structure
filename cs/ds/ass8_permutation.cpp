#include <iostream>
#include <vector>
using namespace std;

int bin_search(vector<int> arr, int t)
{
    int l = 0, r = arr.size() - 1;
    while(r >= l) {
        int mid = (l + r) / 2, mv = arr[mid], lv = arr[l], rv = arr[r];
        if(t == mv) return mid;
        if(t == lv) return l;
        if(t == rv) return r;
        if(t > mv) {
            if(t > lv && mv < lv) l = mid + 1;
            else r = mid - 1;
        }
        else {
            if(t < lv && mv > lv) r = mid - 1;
            else l = mid + 1;
        }
    }
    return - 1;
}

int find_begin(vector<int> arr)
{
    if(arr.front() > arr.back()) return 0;
    int l = 0, r = arr.size() - 1;
    while(r > l) {
        int mid = (l + r) / 2, mv = arr[mid], lv = arr[l], rv = arr[r];
        if(r == l + 1) return r;
        if(mv < lv) l = mid;
        else r = mid;
    }
    return r;
}

int main()
{
    int T;
    cin >> T;
    for(int t = 0; t < T; t ++) {
        int num;
        vector<int> arr, tar;
        while(cin >> num) {
            arr.push_back(num);
            if(cin.get() == '\n') break;
        }
        while(cin >> num) {
            tar.push_back(num);
            if(cin.get() == '\n') break;
        }
        int bg = find_begin(arr);
        for(int i = 0; i < tar.size(); i ++) {
            int idx = bin_search(arr, tar[i]);
            if(idx == - 1) cout << - 1 << endl;
            else {
                if(idx >= bg) cout << idx - bg << endl;
                else cout << arr.size() - bg + idx << endl;
            }
        }
    }
    return 0;
}
