#include <bits/stdc++.h>
using namespace std;

int arr[9];
int a[2];
int sum = 0;

void solve() {
    for(int i = 0; i < 9; i++) {
        for(int j = i; j < 9; j++) {
            if(sum - (arr[i] + arr[j]) == 100) {
                a[0] = i;
                a[1] = j;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int& a : arr) {
        cin >> a;
        sum += a;
    }

    sort(arr, arr + 9);
    solve();

    for(int i = 0; i < 9; i++) {
        if(i == a[0] || i == a[1]) 
            continue;
        cout << arr[i] << '\n';
    }
    return 0;

}