#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, max = 0;
    cin >> n >> m;
    vector<int> height(n);
    for(int i = 0; i < n; i++) {
        cin >> height[i];
        if(max < height[i]) {
            max = height[i];
        }
    }

    int mid, min = 0;
    long sum = 0;

    while(min <= max) {
        mid = (min + max) / 2;
        for(int i = 0; i < n; i++) {
            if(height[i] > mid)
                sum += height[i] - mid;
        }

        //printf("min: %d, mid: %d, max: %d, sum: %ld\n", min, mid, max, sum);

        if(sum >= m) {
            min = mid + 1;
        }
        else {
            max = mid - 1;
        }

        sum = 0;
    }

    cout << max << '\n';
}