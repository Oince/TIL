#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[1001][1001];
int visited[2][1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

typedef struct pos {
    bool broken;
    int x;
    int y;
} pos;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    queue<pos> Q;
    visited[0][0][0] = 1;
    Q.push({0, 0, 0});

    while(!Q.empty()) {
        pos cur = Q.front(); Q.pop();

        if(cur.x == n - 1 && cur.y == m - 1) {
            cout << visited[cur.broken][cur.x][cur.y] << '\n';
            return 0;
        }

        for(int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            bool nbroken = cur.broken;

            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if(board[nx][ny] == '0' && visited[nbroken][nx][ny] == 0) {
                visited[nbroken][nx][ny] = visited[cur.broken][cur.x][cur.y] + 1;
                Q.push({nbroken, nx, ny});
            }

            if(board[nx][ny] == '1' && nbroken == 0 && visited[nbroken][nx][ny] == 0) {
                nbroken = 1;
                visited[nbroken][nx][ny] = visited[cur.broken][cur.x][cur.y] + 1;
                Q.push({nbroken, nx, ny});
            }
        }
    }
    cout << -1 << '\n';
}