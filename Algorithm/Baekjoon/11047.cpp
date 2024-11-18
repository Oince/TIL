#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i, count = 0;
    cin >> n >> k;

    int *value = new int[n];

    for(i = 0; i < n; i++) {
        cin >> value[i];
    }

    for(i = n - 1; i >= 0; i--) {
        if(value[i] <= k) {
            count += k / value[i];
            k = k % value[i];
        }
    }
    cout << count;
}