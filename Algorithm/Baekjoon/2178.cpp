#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int map[n][m];
    int visited[n][m];
    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = 1;

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 | nx >= n | ny < 0 | ny >= m)
                continue;
            
            if(map[nx][ny] == 1 && visited[nx][ny] == 0) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = visited[cur.first][cur.second] + 1;
            }
        }
    }

    cout << visited[n - 1][m - 1] << '\n';

}