#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, res = 0;

char map[100][100];
int visited[100][100];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx >= n || nx < 0 || ny >= n || ny < 0) {
                continue;
            }

            if(map[x][y] == map[nx][ny] && visited[nx][ny] <= 0) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
            }
        }

    }
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) {
            map[i][j] = s[j];
        }
    }    

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j] <= 0) {
                bfs(i, j);
                res++;
            } 
        }
    }

    cout << res << " ";
    res = 0;
    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] == 'G') {
                map[i][j] = 'R';
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j] <= 0) {
                bfs(i, j);
                res++;
            } 
        }
    }
    
    cout << res << '\n';
}