/*
This file provides a cpp solution to the "Remove Nth Node From End of List"
*/

#include <iostream>
#include <string>
using namespace std;
typedef char T;

typedef struct StrListNode* ListNode;
struct StrListNode
{
    T element;
    ListNode next;
};

typedef class LinkList LinkList;
class LinkList
{
private:
    ListNode head, fence;
    int node_cnt;
    void test();
public:
    LinkList()
    {
        head = new struct StrListNode;
        head ->next = nullptr;
        fence = head;
        node_cnt = 0;
    }

    bool insert(T ele)
    {
        ListNode tmp = new struct StrListNode;
        tmp ->element = ele;
        tmp ->next = fence ->next;
        fence ->next = tmp;
        fence = tmp;
        node_cnt ++;
        return true;
    }

    bool delete_back(int idx)
    {
        if(! node_cnt || ! idx || node_cnt < idx) return false;
        ListNode cur = head ->next;
        int dis = node_cnt - idx - 1;
        while(dis --) cur = cur ->next;
        ListNode tmp = cur ->next;
        cur ->next = tmp ->next;
        delete tmp;
        node_cnt --;
        return true;
    }

    void show()
    {
        ListNode cur = head ->next;
        while(cur){
            cout << cur ->element;
            cur = cur ->next;
        }
        cout << endl;
        test();
        return;
    }
};

void LinkList::test() { cout << "test" << endl; }

int main()
{
    int num_cases;
    cin >> num_cases;
    while(num_cases --) {
        string str;
        int idx;
        cin >> str >> idx;
        LinkList ll;
        for(T ele: str) ll.insert(ele);
        ll.delete_back(idx);
        ll.show();
    }
    return 0;
}
