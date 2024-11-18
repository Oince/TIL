#include <iostream>
using namespace std;

int main() {
    int n, t, p;
    cin >> n;

    int size[6] = {0};
    for(int i = 0; i < 6; i++) {
        cin >> size[i];
    }

    cin >> t >> p;

    int t_cnt = 0;
    int sum = 0;
    for(int i = 0; i < 6; i++) {
        sum += size[i];

        if(size[i] == 0) {
            continue;
        }
        else if(size[i] % t == 0) {
            t_cnt += size[i] / t;
        }
        else {
            t_cnt += (size[i] / t) + 1;
        }
    }

    cout << t_cnt << '\n';
    cout << sum / p << " " << sum % p << '\n';
    return 0;
}