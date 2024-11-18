#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int i, j;
    for(i = 1; i <= n; i++) {
        for(j = 0; j < i; j++) {
            cout << "*";
        }
        for(j = 0; j < 2 * (n - i); j++) {
            cout << " ";
        }
        for(j = 0; j < i; j++) {
            cout << "*";
        }
        cout << '\n';
    }
    for(i = n - 1; i > 0; i--) {
        for(j = 0; j < i; j++) {
            cout << "*";
        }
        for(j = 0; j < 2 * (n - i); j++) {
            cout << " ";
        }
        for(j = 0; j < i; j++) {
            cout << "*";
        }
        cout << '\n';
    }

}