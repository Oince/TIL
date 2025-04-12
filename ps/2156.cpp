#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000];
int dp[10000];

int main() {
    int n, candidiate ,i;
    cin >> n;

    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max({dp[1], arr[0] + arr[2], arr[1] + arr[2]});

    for(i = 3; i < n; i++) {
        candidiate = max(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i];
        dp[i] = max(candidiate, dp[i - 1]);
    }

    cout << dp[n - 1] << '\n';

}