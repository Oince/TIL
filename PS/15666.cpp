#include <bits/stdc++.h>
using namespace std;

int n, m;
int input[10];
int arr[10];

void func(int depth, int start) {
    if(depth == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int tmp = 0;
    for(int i = start; i < n; i++) {
        if(tmp != input[i]) {
            tmp = arr[depth] = input[i];
            func(depth + 1, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    sort(input, input + n);

    func(0, 0);

}