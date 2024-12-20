#include <bits/stdc++.h>
using namespace std;

int arr[9];
bool visited[9];
int n, m;

void func(int depth) {
    if(depth == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            arr[depth] = i;
            visited[i] = true;
            func(depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func(0);
}