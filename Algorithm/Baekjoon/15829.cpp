#include <iostream>
using namespace std;

int main() {
    const int r = 31, M = 1234567891;
    int l;
    string s;
    cin >> l >> s;

    long long res = 0, R = 1;

    for(int i = 0; i < l; i++) {
        res += ((s[i] - 96) * R) % M;
        R = (R * r) % M;
    }

    cout << res % M << '\n';
}