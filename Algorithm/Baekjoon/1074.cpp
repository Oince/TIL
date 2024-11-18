#include <iostream>
#include <cmath>
using namespace std;

int N, row, col;
long res = 0;

void z(int n, int r, int c) {
    if(r == row && c == col) {
        return;
    }

    if(row < r + n / 2 && col < c + n / 2) {
        return z(n / 2, r, c);
    }
    else if(row < r + n / 2 && col >= c + n / 2) {
        res += (long)n * n / 4;
        return z(n / 2, r, c + n / 2);
    }
    else if(row >= r + n / 2 && col < c + n / 2) {
        res += (long)2 * n * n / 4;
        return z(n / 2, r + n / 2, c);
    }
    else {
        res += (long)3 * n * n / 4;
        return z(n / 2, r + n / 2, c + n / 2);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> row >> col;

    int power = (int)pow(2, N);

    z(power, 0, 0);

    cout << res << '\n';
    return 0;
}