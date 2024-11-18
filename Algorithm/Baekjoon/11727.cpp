#include <iostream>
#include <algorithm>
#define M 10007
using namespace std;

int c[1001][1001];

int two_pow(int i) {
    if(i == 0) {
        return 1;
    }
    return (2 * two_pow(i - 1)) % M;
}

int main() {
    int n, res = 1;
    cin >> n;

    c[1][1] = 1;
    c[2][0] = 1;
    c[2][1] = 2;
    c[2][2] = 1;

    for(int i = 3; i <= n; i++) {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % M;
        }
    }

    for(int i = 1; i <= n; i++) {
        res = (res + (c[n - i][i] * two_pow(i)) % M) % M;
    }

    cout << res << '\n';

}