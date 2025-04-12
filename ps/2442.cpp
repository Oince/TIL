#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int i, j;
    for(i = 1; i <= n; i++) {
        for(j = 0; j < n - i; j++) {
            cout << " ";
        }
        for(j = 0; j < 2 * i - 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}