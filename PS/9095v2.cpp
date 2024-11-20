#include <iostream>
#include <vector>
using namespace std;

int main() {
    int res[11] = {0};

    res[1] = 1;
    res[2] = 2;
    res[3] = 4;

    for(int i = 4; i <= 10; i++) {
        res[i] = res[i - 1] + res[i - 2] + res[i - 3];
    }

    int n;
    cin >> n;
    while(n > 0) {
        int input;
        cin >> input;

        cout << res[input] << '\n';
        n--;
    }
}