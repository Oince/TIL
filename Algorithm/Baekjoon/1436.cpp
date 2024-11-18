#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;

    int res = 665;
    do {
        res++;
        if(to_string(res).find("666") != string::npos) {
            cnt++;
        }
    } while(cnt != n);

    cout << res << '\n';

    return 0;
}