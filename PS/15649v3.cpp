#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int arr[n];

    for(int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    do {
        reverse(arr + m, arr + n);
        for(int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';

    } while(next_permutation(arr, arr + n));

}