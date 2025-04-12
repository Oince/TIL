#include <bits/stdc++.h>
using namespace std;

char video[64][64];

bool check(int n, int x, int y) {
    for(int i = x; i < n + x; i++) {
        for(int j = y; j < n + y; j++) {
            if(video[x][y] != video[i][j])
                return false;
        }
    }

    return true;
}

void func(int n, int x, int y) {
    if(check(n, x, y)) {
        cout << video[x][y];
        return;
    }

    int half = n / 2;

    cout << "(";
    func(half, x, y);
    func(half, x, y + half);
    func(half, x + half, y);
    func(half, x + half, y + half);
    cout << ")";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> video[i][j];
        }
    }

    func(n, 0, 0);
}