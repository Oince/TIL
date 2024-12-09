#include <bits/stdc++.h>
using namespace std;

int n;
char board[25][25];
int visited[25][25];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    int cnt = 0;
    q.push({x, y});
    visited[x][y] = 1;

    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        cnt++;

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) 
                continue;

            if(board[nx][ny] == '1' && visited[nx][ny] == 0) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    return cnt;
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

    int num = 0;
    vector<int> result;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == '1' && visited[i][j] == 0) {
                num++;
                visited[i][j] = 1;
                result.push_back(bfs(i, j));
            }
        }
    }

    sort(result.begin(), result.end(), less<int>());

    cout << num << '\n';
    for(int i : result) {
        cout << i << '\n';
    }


}