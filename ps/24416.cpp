#include <iostream>
using namespace std;

int rec_cnt = 0;
int dp_cnt = 0;

int fib(int n) {
    if(n == 1 || n == 2) {
        rec_cnt++;
        return 1;
    }
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

int fibonacci(int n) {
    int f[n + 1] = {0};
    f[2] = f[1] = 1;
    for(int i = 3; i <= n; i++) {
        dp_cnt++;
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main() {
    int n;
    cin >> n;
    fib(n);
    fibonacci(n);

    cout << rec_cnt << '\n';
    cout << dp_cnt << '\n';
}