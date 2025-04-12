#include <bits/stdc++.h>
using namespace std;

int n, m, year = 0;
int board[301][301];
int visited[301][301];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool out_of_bound(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m)
        return true;

    return false;
}

void melting() {
    int melt[301][301];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            melt[i][j] = 0;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0)
                continue;

            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(out_of_bound(nx, ny))
                    continue;

                if(board[nx][ny] == 0) {
                    melt[i][j]++;
                }                
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            board[i][j] = max(0, board[i][j] - melt[i][j]);
        }
    }
}

int status() {
    int x = -1, y = -1;
    int cnt1 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] > 0) {
                x = i;
                y = j;
                cnt1++;
            }
        }
    }

    if(cnt1 == 0)
        return 0;

    int cnt2 = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        cnt2++;

        for(int i = 0 ; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(out_of_bound(nx, ny))
                continue;

            if(board[nx][ny] > 0 && visited[nx][ny] == 0) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    if(cnt1 == cnt2) {
        return 1;
    }
    
    return 2;

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    while(true) {
        year++;
        melting();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                visited[i][j] = 0;
            }
        }

        int check = status();
        if(check == 0) {
            cout << 0 << '\n';
            return 0;
        }
        else if(check == 2) {
            cout << year << '\n';
            return 0;
        }
    }
}