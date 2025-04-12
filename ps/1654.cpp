#include <iostream>
using namespace std;

int main() {
    int k, n, i, res = 0;
    long long min = 1, mid = 0, max = 0, cnt = 0;
    cin >> k >> n;
    int *length = new int[k];

    for(i = 0; i < k; i++) {
        cin >> length[i];
        max += length[i];
    }
    max = max / n;

    while(min <= max) {
        mid = (min + max) / 2;
        for(i = 0; i < k; i++) {
            cnt += length[i] / mid;
        }
        printf("min: %d, max: %d, mid: %d, cnt: %d\n", min, max, mid, cnt);
        if(cnt <= n) {
            max = mid - 1;
        }
        else {
            min = mid + 1;
        }
        cnt = 0;
    }

    cout << max << '\n';
    
}