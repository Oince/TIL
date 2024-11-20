#include <iostream>
using namespace std;

int dp[101][10];

int main() {
    int n;
    cin >> n;

    const int M = 1000000000;

    dp[1][0] = 0;
    for(int j = 1; j <= 9; j++) {
        dp[1][j] = 1;
    }    

    for(int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1];
        for(int j = 1; j <= 8; j++) {
            dp[i][j] = (dp[i - 1][j - 1] % M + dp[i - 1][j + 1] % M) % M;
        }
        dp[i][9] = dp[i - 1][8];
    }

    long res = 0;
    for(int j = 0; j < 10; j++) {
        res = (res % M + dp[n][j] % M) % M;
    }

    cout << res << '\n';
}