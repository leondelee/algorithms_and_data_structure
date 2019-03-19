#include <iostream>
#include <string>
using namespace std;

template <class T>
class ListNode {
public:
    T val;
    ListNode *next;
    ListNode() : next(NULL) {}
    ListNode(T& x) : val(x), next(NULL) {}
};

template <class T>
class List {
private:
     ListNode<T>* head;
     ListNode<T>* tail;
     void init();
     void removeAll();
public:
     List() {init();}
     ~List() {removeAll();}
     void clear() {removeAll(); init();}
     void pushBack(T& elem);  // Insert the element at the end of the list
     void printAll();  // Print the result (all elements in the list)
     void partition(int x);  // Do the partition required in the problem
};

template<class T>
void List<T>::init()
{
    head = tail = new ListNode<T>;
}

template <class T>
void List<T>::removeAll()
{
    ListNode<T> *fence = head ->next;
    while(fence) {
        ListNode<T> *tmp = fence ->next;
        delete fence;
        fence = tmp;
    }
}

template <class T>
void List<T>::pushBack(T& elem)
{
    tail ->next = new ListNode<T>(elem);
    tail = tail ->next;
}

template <class T>
void List<T>::printAll()
{
    ListNode<T> *fence = head ->next;
    while(fence) {
        cout << fence ->val;
        if(fence ->next) cout << ' ';
        fence = fence ->next;
    }
}

template <class T>
void List<T>::partition(int x)
{
    ListNode<T> *headSmall = NULL, *headBig = NULL, *curSmall = NULL, *curBig = NULL, *fence = head ->next;
    while(fence) {
        if(fence ->val < x && !headSmall) headSmall = curSmall = fence;
        else if(fence ->val < x) {
            curSmall ->next = fence;
            curSmall = curSmall ->next;
        }
        else if(fence ->val >= x && !headBig) headBig = curBig = fence;
        else if(fence ->val >= x) {
            curBig ->next = fence;
            curBig = curBig ->next;
        }
        fence = fence ->next;
    }
    if(! headSmall || ! headBig) return;
    curSmall ->next = headBig;
    curBig ->next = NULL;
    head ->next = headSmall;
    return;
}


int main() {
     int num_cases, num, digit;
     cin >> num_cases;
     List<int> l;
     for(int t = 0; t < num_cases; t ++) {
        l.clear();
        while(cin >> digit) {
            l.pushBack(digit);
            if(cin.get() == '\n') break;
        }
        cin >> num;
        l.partition(num);
        l.printAll();
        cout << endl;
     }
}
