#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int r, c;
int board[1001][1001];
int jihun_visited[1001][1001];
int fire_visited[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    queue<pair<int, int>> fq;
    queue<pair<int, int>> jq;

    
    for(int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < c; j++) {
            if(s[j] == '.') {
                board[i][j] = 1;
            }
            else if(s[j] == 'F') {
                fq.push({i, j});
                fire_visited[i][j] = 1;
            }
            else if(s[j] == 'J') {
                jq.push({i, j});
                jihun_visited[i][j] = 1;
            }
        }
    }

    while(!fq.empty()) {
        pair<int, int> cur = fq.front(); fq.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;

            if(fire_visited[nx][ny] == 0 && board[nx][ny] == 1) {
                fire_visited[nx][ny] = fire_visited[cur.X][cur.Y] + 1;
                fq.push({nx, ny});
            }
        }
    }

    int ans = 1000000000;
    while(!jq.empty()) {
        pair<int, int> cur = jq.front(); jq.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c) {
                cout << jihun_visited[cur.X][cur.Y]<< '\n';
                return 0;
            }
                

            if(jihun_visited[nx][ny] > 0 || board[nx][ny] == 0)  
                continue;

            //불이 벽에 가로막힌 경우도 생각해야함
            //fire_visited[nx][ny] == 0 이라면 불이 도달하지 못하는 곳이라는 뜻
            //지훈이가 진행할 수 있는 장소이기 때문에 해당 조건을 체크해줘야 함
            if(fire_visited[nx][ny] != 0 && fire_visited[nx][ny] <= jihun_visited[cur.X][cur.Y] + 1)
                continue;

            jihun_visited[nx][ny] = jihun_visited[cur.X][cur.Y] + 1;
            jq.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE\n";


}