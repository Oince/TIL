#include <bits/stdc++.h>
using namespace std;

int board[1001][1001];
int visited[2][1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

typedef struct pos {
    int broken;
    int x;
    int y;
} pos;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m; 

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    queue<pos> q;
    q.push({0, 0, 0});
    visited[0][0][0] = visited[1][0][0] = 1;

    while(!q.empty()) {
        pos cur = q.front(); q.pop();

        //도착지 도착
        if(cur.x == n - 1 && cur.y == m - 1) {
            cout << visited[cur.broken][cur.x][cur.y] << '\n';
            return 0;
            // break;
        }

        int nextdist = visited[cur.broken][cur.x][cur.y] + 1;
        for(int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nbroken = cur.broken;

            //범위 벗어나면 다음 방문
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            //길이 있고, 방문하지 않았으면 방문함
            if(board[nx][ny] == 0 && visited[nbroken][nx][ny] == 0) {
                visited[nbroken][nx][ny] = nextdist;
                q.push({nbroken, nx, ny});
            }

            //길이 없지만 벽을 부순적이 없고, 방문하지 않았으면 방문 
            if(board[nx][ny] == 1 && cur.broken == 0 && visited[1][nx][ny] == 0) {
                visited[1][nx][ny] = nextdist;
                q.push({1, nx, ny});
            }
        }
    }

    // cout << "visited[0][][]\n";
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << visited[0][i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    // cout << "visited[1][][]\n";
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << visited[1][i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    cout << -1 << '\n';
}