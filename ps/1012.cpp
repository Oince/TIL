#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int map[50][50];
int visited[50][50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int m, n, k;

void bfs(int x, int y) {
    
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;

            if(visited[nx][ny] == 0 && map[nx][ny] == 1) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t > 0) {
        cin >> m >> n >> k;

        memset(visited, 0, sizeof(visited));
        memset(map, 0, sizeof(map));

        for(int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            map[x][y] = 1;
        }

        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j] == 0 && map[i][j] == 1) {
                    bfs(i, j);
                    res++;
                }
            }
        }
        cout << res << '\n';
        t--;
    }
}