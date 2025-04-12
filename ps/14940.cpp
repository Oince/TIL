#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> map(n, vector<int>(m, 0));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    pair<int, int> start;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                start = make_pair(i, j);
            }
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    q.push(start);

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        int distance = visited[cur.first][cur.second];

        for(int i = 0; i < 4; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];

            if(x < 0 || x >= n || y < 0 || y >= m || map[x][y] == 0 || visited[x][y] > 0)
                continue;

            q.push(make_pair(x, y));
            visited[x][y] = distance + 1;
        }
        
    }
    visited[start.first][start.second] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j] == 0 && map[i][j] == 1)
                visited[i][j] = -1;
            cout << visited[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
