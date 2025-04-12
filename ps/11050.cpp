#include <iostream>
using namespace std;

int b[11][11];

int bin(int n, int k) {
    if(b[n][k]) {
        return b[n][k];
    }
    else if(n == k || k == 0) {
        return b[n][k] = 1;
    }
    else {
        return b[n][k] = bin(n - 1, k - 1) + bin(n - 1, k);
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << bin(n, k) << '\n';
}