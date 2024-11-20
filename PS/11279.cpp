#include <iostream>
#include <algorithm>
using namespace std;

class Heap {
private:
    int heap[100001];
    int size;

    void swap(int parent, int child) {
        int swp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = swp;
    }

public:
    Heap() {
        this->size = 0;
    }

    void push(int x) {
        heap[++size] = x;
        if(size > 1) {
            int child = size;
            while(child / 2 > 0 && heap[child / 2] < heap[child]) {
                swap(child / 2, child);
                child = child / 2;
            }
        }
    }

    int pop() {
        if(size <= 0) {
            return 0;
        }
        int child = 1;
        int ret = heap[1];
        heap[1] = heap[size--];

        while(child * 2 <= size) {
            if(size == child * 2) {
                if(heap[child] < heap[child * 2]) {
                    swap(child, child * 2);
                }
                break;
            }

            if(heap[child] > heap[child * 2] && heap[child] > heap[child * 2 + 1]) {
                break;
            }

            if(heap[child * 2] > heap[child * 2 + 1]) {
                swap(child, child * 2);
                child = child * 2;
            }
            else {
                swap(child, child * 2 + 1);
                child = child * 2 + 1;
            }
        } 

        return ret;
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, x;
    cin >> n;

    Heap h;

    while(n > 0) {
        cin >> x;
        if(x == 0) {
            cout << h.pop() << '\n';
        }
        else {
            h.push(x);
        }
        n--;
    }
}