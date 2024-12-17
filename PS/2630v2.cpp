#include <bits/stdc++.h>
using namespace std;

int N;
int board[128][128];
int ans[2];

bool check(int n, int x, int y) {
    for(int i = x; i < n + x; i++) {
        for(int j = y; j < n + y; j++) {
            if(board[x][y] != board[i][j])
                return false;
        }
    }

    return true;
}

void func(int n, int x, int y) {

    if(check(n, x, y)) {
        ans[board[x][y]]++;
        return;
    }

    int half = n / 2;

    func(half, x, y);
    func(half, x + half, y);
    func(half, x, y + half);
    func(half, x + half, y + half);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    func(N, 0, 0);

    cout << ans[0] << '\n' << ans[1] << '\n';
}