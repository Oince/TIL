#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    int b[n + 1][k + 1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= min(i ,k); j++) {
            if(i == j || j == 0) {
                b[i][j] = 1;
            }
            else {
                b[i][j] = b[i - 1][j - 1] + b[i - 1][j];
            }
        }
    }

    cout << b[n][k] << '\n';
}