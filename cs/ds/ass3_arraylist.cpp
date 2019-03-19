#include <iostream>
#include <string>
using namespace std;

template<class T>
class LinkNode
{
public:
    T value;
    LinkNode<T> *next;
    LinkNode()
    {
        next = NULL;
    }

    LinkNode(T val)
    {
        value = val;
        next = NULL;
    }
};

template<class T>
class ArrayList
{
private:
    LinkNode<T> *head, *fence;
public:
    ArrayList(string s = "")
    {
        head = new LinkNode<T>;
        fence = head;
        int len = s.size();
        for(int i = 0; i < len; i ++) {
            int dg = (T) s[i];
            insert(dg);
        }
    }

    ~ArrayList()
    {
        fence = head;
        while(fence) {
            LinkNode<T> *tmp = fence ->next;
            delete tmp;
            fence = tmp;
        }
    }

    LinkNode<T>* get_head()
    {
        return head;
    }

    bool empty()
    {
        return head ->next == NULL;
    }

    void insert(T val)
    {
        fence ->next = new LinkNode<T>(val);
        fence = fence ->next;
    }

    void show()
    {
        if(empty()) return;
        LinkNode<T> *cur = head ->next;
        while(cur) {
            cout << cur ->value;
            cur = cur ->next;
        }
        cout << endl;
    }

    void operator+=(ArrayList<T>& B)
    {
        if(! B.empty()) fence ->next = B.get_head() ->next;
    }
};


int main()
{
    int N;
    cin >> N;
    while(N --) {
        string s1, s2;
        cin >> s1 >> s2;
        ArrayList<char> A(s1), B(s2);
        if(! A.empty()) {
            A += B;
            A.show();
        }
        else B.show();
    }
    return 0;
}
