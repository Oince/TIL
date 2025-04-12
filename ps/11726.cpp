#include <iostream>
#define M 10007
using namespace std;


int dp[1000];

int main() {
    int n, res = 0;
    cin >> n;

    dp[0] = 1;
    dp[1] = 2;

    for(int i = 2; i < n; i++) {
        dp[i] = (dp[i - 1] % M + dp[i - 2]% M) % M;
    }

    cout << dp[n - 1] << '\n';
}