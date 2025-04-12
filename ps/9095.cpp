#include <iostream>
using namespace std;

int main() {
    int res[11] = {0,};

    res[1] = 1;
    res[2] = 2;
    res[3] = 4;

    for(int i = 4; i < 11; i++) {
        res[i] = res[i - 1] + res[i - 2] + res[i - 3];
    }

    int t;
    cin >> t;

    while(t > 0) {
        int n;
        cin >> n;
        cout << res[n] << '\n';
        t--;
    }
}