#include <bits/stdc++.h>
using namespace std;

char building[31][31][31];
int visited[31][31][31];

int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

typedef struct pos {
    int x;
    int y;
    int z;
} pos;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int l, r, c;

    while(true) {
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0) 
            break;

        for(int i = 0; i < l; i++) {
            for(int j = 0; j < r; j++) {
                for(int k = 0; k < c; k++) {
                    visited[i][j][k] = -1;
                }
            }
        }

        pos start;
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < r; j++) {
                for(int k = 0; k < c; k++) {
                    cin >> building[i][j][k];
                    if(building[i][j][k] == 'S') {
                        start.x = i;
                        start.y = j;
                        start.z = k;
                    }
                }
            }
        }

        queue<pos> q;
        q.push(start);
        visited[start.x][start.y][start.z] = 0;

        int ans = -1;
        while(!q.empty()) {
            pos cur = q.front(); q.pop();

            if(building[cur.x][cur.y][cur.z] == 'E') {
                ans = visited[cur.x][cur.y][cur.z];
                break;
            }

            for(int i = 0; i < 6; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                int nz = cur.z + dz[i];

                if(nx < 0 || nx >= l || ny < 0 || ny >= r || nz < 0 || nz >= c)
                    continue;

                if((building[nx][ny][nz] == '.' || building[nx][ny][nz] == 'E') && visited[nx][ny][nz] == -1) {
                    visited[nx][ny][nz] = visited[cur.x][cur.y][cur.z] + 1;
                    q.push({nx, ny, nz});
                }
            }
        }

        if(ans == -1) {
            cout << "Trapped!\n";
        }
        else {
            cout << "Escaped in " << ans << " minute(s).\n";
        }
    }
}