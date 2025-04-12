#include <bits/stdc++.h>
using namespace std;

int n;
int board[101][101];
bool visited[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y, int k) {
    queue<pair<int, int>> q;
    visited[x][y] = 1;
    q.push({x, y});

    while(!q.empty()) {
        auto cur = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
                
            if(board[nx][ny] > k && visited[nx][ny] == 0) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 1;
    for(int k = 1; k < 100; k++) {

        for(int i = 0; i < n; i++) {
            fill(visited[i], visited[i] + n, 0);
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] > k && visited[i][j] == 0) {
                    cnt++;
                    bfs(i, j, k);
                }
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans << '\n';
}