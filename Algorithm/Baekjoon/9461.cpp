#include <iostream>
using namespace std;

long long dp[101] = {0};

int main() {
    int t;
    cin >> t;

    dp[3] = dp[2] = dp[1] = 1;
    dp[5] = dp[4] = 2;

    for(int i = 6; i <= 100; i++) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    while(t > 0) {
        int n;
        cin >> n;

        cout << dp[n] << '\n';
        t--;
    }
}