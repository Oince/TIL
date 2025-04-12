#include <iostream>
#define M 10007
using namespace std;

int dp[1000];

int main() {
    int n;
    cin >> n;

    dp[0] = 1;
    dp[1] = 3;

    for(int i = 2; i < n; i++) {
        dp[i] = (dp[i - 1] + 2*dp[i - 2]) % M;
    }

    cout << dp[n - 1] << '\n';
}