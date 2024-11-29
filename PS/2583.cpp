#include <bits/stdc++.h>
using namespace std;

int m, n, k;

bool board[101][101];
bool visited[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    visited[x][y] = 1;

    int area = 0;

    while(!Q.empty()) {
        area++;
        pair<int, int> cur = Q.front(); Q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;

            if(board[nx][ny] == 0 && visited[nx][ny] == 0) {
                visited[nx][ny] = 1;
                Q.push({nx, ny});
            }
        }
    }

    return area;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;

    while(k--) {
        pair<int, int> start, end;
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;

        for(int i = start.second; i < end.second; i++) {
            for(int j = start.first; j < end.first; j++) {
                board[i][j] = 1;
            }
        }
    }

    int cnt = 0;
    priority_queue<int, vector<int>, greater<int>> area;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 0 && visited[i][j] == 0) {
                cnt++;
                area.push(bfs(i, j));
            }
        }
    }
    
    cout << cnt << '\n';
    while(!area.empty()) {
        cout << area.top() << " ";
        area.pop();
    }
}