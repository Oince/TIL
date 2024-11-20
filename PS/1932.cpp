#include <iostream>
#include <algorithm>
using namespace std;

int dp[500][500];

int main() {
    int n, res = 0;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> dp[i][j];
        }
    }

    for(int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i][0];
        dp[i][i] = dp[i - 1][i - 1] + dp[i][i];
    }

    for(int i = 2; i < n; i++) {
        for(int j = 1; j < i; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + dp[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        if(res < dp[n - 1][i]) {
            res = dp[n - 1][i];
        }
    }

    cout << res << '\n';
}