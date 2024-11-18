#include <iostream>
using namespace std;

class Heap {
private:
    pair<int, bool> heap[100001];
    int size;

    void swap(int parent, int child) {
        pair<int, bool> swp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = swp;
    }

public:
    Heap() {
        this->size = 0;
    }

    void push(int x) {
        pair<int, bool> item;
        if(x > 0) {
            item = make_pair(x, 1);
        }
        else {
            item = make_pair(-x, 0);
        }
        heap[++size] = item;

        if(size > 1) {
            int cur = size;
            while(cur / 2 > 0 && heap[cur / 2].first >= heap[cur].first) {
                if(heap[cur / 2].first == heap[cur].first && heap[cur / 2].second < heap[cur].second) {
                    break;
                }
                swap(cur / 2, cur);
                cur = cur / 2;
            }
        }
    }

    int pop() {
        if(size <= 0) {
            return 0;
        }
        int cur = 1;
        pair<int, bool> ret = heap[1];
        heap[1] = heap[size--];

        while(cur * 2 <= size) {
            if(size == cur * 2) {
                if(heap[cur].first > heap[cur * 2].first ||
                    (heap[cur].first == heap[cur * 2].first && heap[cur].second > heap[cur * 2].second) ) {
                    swap(cur, cur * 2);
                }
                break;
            }

            if(heap[cur].first < heap[cur * 2].first && heap[cur].first < heap[cur * 2 + 1].first) {
                break;
            }

            if(heap[cur * 2].first < heap[cur * 2 + 1].first) {
                if(heap[cur * 2].first == heap[cur].first && heap[cur * 2].second > heap[cur].second) {
                    break;
                }
                swap(cur, cur * 2);
                cur = cur * 2;
            }
            else if(heap[cur * 2].first > heap[cur * 2 + 1].first){
                if(heap[cur * 2 + 1].first == heap[cur].first && heap[cur * 2 + 1].second > heap[cur].second) {
                    break;
                }
                swap(cur, cur * 2 + 1);
                cur = cur * 2 + 1;
            }
            else {
                if(heap[cur * 2].second < heap[cur * 2 + 1].second) {
                    if(heap[cur * 2].first == heap[cur].first && heap[cur * 2].second > heap[cur].second) {
                        break;
                    }
                    swap(cur, cur * 2);
                    cur = cur * 2;
                }
                else {
                    if(heap[cur * 2 + 1].first == heap[cur].first && heap[cur * 2 + 1].second > heap[cur].second) {
                        break;
                    }
                    swap(cur, cur * 2 + 1);
                    cur = cur * 2 + 1;
                }

            }
        } 

        if(ret.second == 0) {
            return -ret.first;
        }
        else {
            return ret.first;
        }
    }

    // void print() {
    //     for(int i = 1; i <= size; i++) {
    //         cout << heap[i].first << heap[i].second << " ";
    //     }
    //     cout << '\n';
    // }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    Heap h;

    while(n > 0) {
        int input;
        cin >> input;

        if(input == 0) {
            cout << h.pop() << '\n';
        }
        else {
            h.push(input);
        }

        n--;
    }


}