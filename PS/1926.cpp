#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int board[505][505];
bool visited[505][505];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

int bfs() {
    int extent = 0;
    while(!q.empty()) {
        extent++;
        pair<int, int> cur = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            
            if(visited[nx][ny] == 0 && board[nx][ny] == 1) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    return extent;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int count = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j] == 1 || board[i][j] == 0)
                continue;

            visited[i][j] = 1;
            q.push({i, j});
            count++;
            ans = max(ans, bfs());
        }
    }
    cout << count << '\n' << ans << '\n';

}