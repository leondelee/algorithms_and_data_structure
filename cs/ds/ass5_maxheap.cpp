#include <iostream>
using namespace std;
#define MAXSIZE 105

class PriorityQueue {
private:
    int rear;
    int *array;

    void my_swap(int x, int y)
    {
        int tmp = array[x];
        array[x] = array[y];
        array[y] = tmp;
    }

    void siftup()
    {
        int idx = rear - 1;
        while(idx > 0) {
            int p = (idx - 1) / 2;
            if(array[idx] > array[p]) my_swap(idx, p);
            else break;
            idx = p;
        }
    }

    void siftdown()
    {
        int cur = 0;
        while(cur < rear) {
            int lchild = 2 * cur + 1;
            int rchild = 2 * cur + 2;
            int idx = cur;
            if(lchild < rear && array[lchild] > array[idx]) idx = lchild;
            if(rchild < rear && array[rchild] > array[idx]) idx = rchild;
            if(idx != cur) {
                my_swap(idx, cur);
                cur = idx;
            }
            else break;
        }
    }

public:
    PriorityQueue() {
        array = new int[MAXSIZE];
        rear = 0;
    }

    int dequeue() {
        int res = array[0];
        array[0] = array[-- rear];
        siftdown();
        return res;
    }

    void enqueue(int elem) {
        array[rear ++] = elem;
        siftup();
    }

    int front() { return array[0]; }

    void show()
    {
        for(int i = 0; i < rear; i ++) cout << array[i] << " ";
        cout << endl;
    }
};

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; t ++) {
        int n, m;
        cin >> n >> m;
        PriorityQueue pq;
        for(int j = 0; j < n; j ++) {
            int cur;
            cin >> cur;
            pq.enqueue(cur);
        }
        for(int k = 0; k < m; k ++) {
            char op;
            cin >> op;
            if(op == 'I') {
                int dig;
                cin >> dig;
                pq.enqueue(dig);
            }
            else {
                pq.dequeue();
            }
            cout << pq.front();
            if(t != T - 1 || k != m - 1) cout << endl;
        }
    }
    return 0;
}
