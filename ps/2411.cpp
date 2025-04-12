#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int i, j;
    for(i = 0; i < n; i++) {
        for(j = i; j > 0; j--) {
            cout << " ";
        }
        for(j = 0; j < n - i; j++) {
            cout << "*";
        }
        cout << '\n';
    }
}