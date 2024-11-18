#include <iostream>
#include <queue>
using namespace std;

int map[1000][1000];
int visited[1000][1000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, i, j, cnt = 0, res = 0;
    cin >> m >> n;

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    queue<pair<int, int>> q;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(map[i][j] == 1) {
                q.push(make_pair(i, j));
                visited[i][j] = 1;
                cnt++;
            }
            else if(map[i][j] == -1) {
                visited[i][j] = -1;
                cnt++;
            }
            else {
                visited[i][j] = 0;
            }
        
        }
    }

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        if(res < visited[cur.first][cur.second]) {
            res = visited[cur.first][cur.second];
        }

        for(i = 0; i < 4; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];

            if(x < 0 || x >= n || y < 0 || y >= m) {
                continue;
            }

            if(visited[x][y] == 0 && map[x][y] == 0) {
                visited[x][y] = visited[cur.first][cur.second] + 1;
                q.push(make_pair(x, y));
                cnt++;
            }
        }
    }

    if(cnt != n * m) {
        cout << -1 << '\n';
        return 0;
    }

    cout << res - 1 << '\n';
}