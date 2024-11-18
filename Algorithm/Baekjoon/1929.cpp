#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n) {
    if(n <= 1)
        return false;
    float n_sqrt = sqrt(n);
    for(int i = 2; i <= n_sqrt; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int m, n;
    cin >> m >> n;

    for(int i = m; i <= n; i++) {
        if(is_prime(i))
            cout << i << '\n';
    }

}