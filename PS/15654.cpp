#include <bits/stdc++.h>
using namespace std;

int n, m;
int input[10];
int arr[10];
bool visited[10];

void func(int depth) {
    if(depth == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++) {
        if(visited[i] == 0) {
            visited[i] = 1;
            arr[depth] = input[i];
            func(depth + 1);
            visited[i] = 0;
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

    func(0);
}