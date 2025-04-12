#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, i = 1;
    cin >> x;

    while(x > i) {
        x = x - i;
        i++;
    }

    if(i % 2 == 1) {
        cout << i + 1 - x << "/" << x << '\n';
    }
    else {
        cout << x << "/" << i + 1 - x << '\n';
    }

    return 0;
}