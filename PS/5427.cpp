#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string board[1001];

int f_visited[1001][1001];
int s_visited[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int w, h;
        cin >> w >> h;

        queue<pair<int, int>> fq;
        queue<pair<int, int>> sq;
    
        for(int i = 0; i < h; i++) {
            cin >> board[i];
        }

        for(int i = 0; i < h; i++) {
            fill(f_visited[i], f_visited[i] + w, 0);
            fill(s_visited[i], s_visited[i] + w, 0);
        }

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(board[i][j] == '@') {
                    sq.push({i, j});
                    s_visited[i][j] = 1;
                }
                if(board[i][j] == '*') {
                    fq.push({i, j});
                    f_visited[i][j] = 1;
                }
            }
        }

        while(!fq.empty()) {
            pair<int, int> cur = fq.front(); fq.pop();

            for(int i = 0; i < 4; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];

                if(nx < 0 || nx >= h || ny < 0 || ny >= w)
                    continue;

                if(f_visited[nx][ny] > 0 || board[nx][ny] != '.')
                    continue;
                
                fq.push({nx, ny});
                f_visited[nx][ny] = f_visited[cur.X][cur.Y] + 1;
            }
        }

        int ans = -1;
        while(!sq.empty()) {
            pair<int, int> cur = sq.front(); sq.pop();
            if(cur.X == 0 || cur.X == h - 1 || cur.Y == 0 || cur.Y == w - 1) {
                ans = s_visited[cur.X][cur.Y];
                break;
            }
            
            for(int i = 0; i < 4; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];

                if(nx < 0 || nx >= h || ny < 0 || ny >= w)
                    continue;

                if(s_visited[nx][ny] > 0 || board[nx][ny] != '.')
                    continue;
                if(f_visited[nx][ny] != 0 && f_visited[nx][ny] <= s_visited[cur.X][cur.Y] + 1)
                    continue;

                sq.push({nx, ny});
                s_visited[nx][ny] = s_visited[cur.X][cur.Y] + 1;
            }
        }

        if(ans == -1) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            cout << ans << '\n';
        }
    }
}