#include <iostream>
#include <queue>
using namespace std;

int map[100][100][100];
int visited[100][100][100];
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, h, i, j, k, cnt = 0, res = 0;
    cin >> m >> n >> h;

    for(i = 0; i < h; i++) {
        for(j = 0; j < n; j++) {
            for(k = 0; k < m; k++) {
                cin >> map[i][j][k];
            }
        }
    }

    queue<vector<int>> q;
    for(i = 0; i < h; i++) {
        for(j = 0; j < n; j++) {
            for(k = 0; k < m; k++) {
                if(map[i][j][k] == 1) {
                    vector<int> v = {i, j, k};
                    q.push(v);
                    visited[i][j][k] = 1;
                    cnt++;
                }
                else if(map[i][j][k] == -1) {
                    visited[i][j][k] = -1;
                    cnt++;
                }
                else {
                    visited[i][j][k] = 0;
                }
            }
        }
    }

    while(!q.empty()) {
        vector<int> cur = q.front(); q.pop();
        if(res < visited[cur[0]][cur[1]][cur[2]]) {
            res = visited[cur[0]][cur[1]][cur[2]];
        }

        for(i = 0; i < 6; i++) {
            int z = cur[0] + dz[i];
            int x = cur[1] + dx[i];
            int y = cur[2] + dy[i];

            if(x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >= h) {
                continue;
            }

            if(visited[z][x][y] == 0 && map[z][x][y] == 0) {
                visited[z][x][y] = visited[cur[0]][cur[1]][cur[2]] + 1;
                vector<int> v = {z, x, y};
                q.push(v);
                cnt++;
            }
        }
    }

    if(cnt != n * m * h) {
        cout << -1 << '\n';
        return 0;
    }

    cout << res - 1 << '\n';
}