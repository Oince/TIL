#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];
int dp[1000];

int main() {
    int n;
    cin >> n;

    int i, j;
    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int res = 1;
    dp[0] = 1;
    for(i = 1; i < n; i++) {
        dp[i] = 1;
        for(j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        } 
        res = max(dp[i], res);
    }

    cout << res << '\n';
}