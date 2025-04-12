#include <iostream>
using namespace std;
int dp[1000001] = {0,};

int main() {
    const int d = 15746;
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % d;
    }

    cout << dp[n] << '\n';

}