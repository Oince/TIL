#include <iostream>
using namespace std;
int arr[100000] = {0};
int dp[100000] = {0};

int main() {
    int n, i;
    cin >> n;

    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int res = arr[0];
    dp[0] = arr[0];

    for(i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        res = res > dp[i] ? res : dp[i];
    }

    cout << res << '\n';
}