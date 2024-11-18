#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int dp[50001] = {0};

    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1] + 1;
        for(int j = 2; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}