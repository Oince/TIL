#include <bits/stdc++.h>
using namespace std;

char board[4000][7000];

void func(int n, int x, int y) {

    if(n == 3) {
        board[x][y] = '*';
        board[x + 1][y - 1] = board[x + 1][y + 1] = '*';
        board[x + 2][y - 2] = board[x + 2][y - 1] = board[x + 2][y] = board[x + 2][y + 1] = board[x + 2][y + 2] = '*';
        return;
    }

    int next = n / 2;
    func(next, x, y);
    func(next, x + next, y - next);
    func(next, x + next, y + next);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        fill(board[i], board[i] + n * 2 - 1, ' ');
    }

    func(n, 0, n - 1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n * 2 - 1; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    // for(int i = 0; i < n ; i++) {
    //     for(int j = 0; j < n * 2 - 1; j++) {
    //         if(board[i][j] == '*')
    //             cout << '*';
    //         else
    //             cout << ' ';
    //     }
    //     cout << '\n';
    // }


    
}