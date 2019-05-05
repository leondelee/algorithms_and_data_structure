#include <iostream>
using namespace std;

class Heap
{
private:
    int len, max_len;
    int *array;

    void my_swap(int x, int y)
    {
        int tmp = array[x];
        array[x] = array[y];
        array[y] = tmp;
    }

    void siftup()
    {
        int idx = len - 1;
        while(idx > 0) {
            int p = (idx - 1) / 2;
            if(p >= 0 && array[p] > array[idx])
                my_swap(idx, p);
            idx = p;
        }
    }

    void siftdown(int idx)
    {
        int m_idx = idx;
        int lc = 2 * idx + 1;
        int rc = 2 * idx + 2;
        if(lc < len && array[m_idx] > array[lc])
            m_idx = lc;
        if(rc < len && array[m_idx] > array[rc])
            m_idx = rc;
        if(m_idx != idx)
            my_swap(m_idx, idx);
        else return;
        siftdown(m_idx);
    }

public:
    Heap(int K)
    {
        array = new int[K];
        max_len = K;
        len = 0;
    }

    void insert(int x)
    {
        if(len == max_len) {
            if(array[0] < x) {
                array[0] = x;
                siftdown(0);
            }
        }
        else {
            array[len ++] = x;
            siftup();
        }
    }

    void show()
    {
        cout << array[0] << endl;
    }
};
int main()
{
    int N, K;
    cin >> N >> K;
    Heap heap(K);
    for(int i = 0; i < N; i ++) {
        int dig;
        cin >> dig;
        heap.insert(dig);
    }
    heap.show();
    return 0;
}
