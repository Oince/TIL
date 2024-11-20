#include <bits/stdc++.h>
using namespace std;

int arr[10];
int main() {
    int n;
    cin >> n;

    while(n > 0) {
        arr[n % 10]++;
        n = n / 10; 
    }

    arr[6] = (arr[6] + arr[9] + 1) / 2;

    int res = 0;
    for(int i = 0; i < 9; i++) {
        res = max(res, arr[i]);
    }
    cout << res << '\n';


}