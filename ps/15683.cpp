#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, ans = 100;
int blind = 0;
int board[10][10];
int visited[10][10];
vector<pair<int, int>> cctvs;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool OOB(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

//0 -> 오른쪽, 1 -> 아래
//2 -> 왼쪽,  3 -> 위
int visiting(int direction, pair<int, int> start, int depth) {
    auto cur = start;
    int ret = 0;

    cur.X += dx[direction];
    cur.Y += dy[direction];

    while(!OOB(cur.X, cur.Y) && board[cur.X][cur.Y] != 6) {

        if(board[cur.X][cur.Y] == 0 && visited[cur.X][cur.Y] == 0) {
            ret++;
            visited[cur.X][cur.Y] = depth;
        }
        
        cur.X += dx[direction];
        cur.Y += dy[direction];
    }

    // if(direction == 0) {
    //     cur.Y += 1;
    //     while(cur.Y < m && board[cur.X][cur.Y] != 6) {
    //         if(board[cur.X][cur.Y] == 0 && visited[cur.X][cur.Y] == 0) {
    //             ret++;
    //             visited[cur.X][cur.Y] = depth;
    //         }
    //         cur.Y += 1;
    //     }
    // }
    // else if(direction == 1) {
    //     cur.X += 1;
    //     while(cur.X < n && board[cur.X][cur.Y] != 6) {
    //         if(board[cur.X][cur.Y] == 0 && visited[cur.X][cur.Y] == 0) {
    //             ret++;
    //             visited[cur.X][cur.Y] = depth;
    //         }
    //         cur.X += 1;
    //     }
    // }
    // else if(direction == 2) {
    //     cur.Y -= 1;
    //     while(cur.Y >= 0 && board[cur.X][cur.Y] != 6) {
    //         if(board[cur.X][cur.Y] == 0 && visited[cur.X][cur.Y] == 0) {
    //             ret++;
    //             visited[cur.X][cur.Y] = depth;
    //         }
    //         cur.Y -= 1;
    //     }
    // }
    // else if(direction == 3) {
    //     cur.X -= 1;
    //     while(cur.X >= 0 && board[cur.X][cur.Y] != 6) {
    //         if(board[cur.X][cur.Y] == 0 && visited[cur.X][cur.Y] == 0) {
    //             ret++;
    //             visited[cur.X][cur.Y] = depth;
    //         }
    //         cur.X -= 1;
    //     }
    // }

    return ret;
}

//0 -> 오른쪽, 1 -> 아래
//2 -> 왼쪽,  3 -> 위
void unvisiting(int direction, pair<int, int> start, int depth) {
    auto cur = start;

    cur.X += dx[direction];
    cur.Y += dy[direction];

    while(!OOB(cur.X, cur.Y) && board[cur.X][cur.Y] != 6) {

        if(board[cur.X][cur.Y] == 0 && visited[cur.X][cur.Y] == depth) 
            visited[cur.X][cur.Y] = 0;
        
        cur.X += dx[direction];
        cur.Y += dy[direction];
    }

    // if(direction == 0) {
    //     cur.Y += 1;
    //     while(cur.Y < m && board[cur.X][cur.Y] != 6) {
    //         if(board[cur.X][cur.Y] == 0 && visited[cur.X][cur.Y] == depth) {
    //             visited[cur.X][cur.Y] = 0;
    //         }
    //         cur.Y += 1;
    //     }
    // }
    // else if(direction == 1) {
    //     cur.X += 1;
    //     while(cur.X < n && board[cur.X][cur.Y] != 6) {
    //         if(board[cur.X][cur.Y] == 0 && visited[cur.X][cur.Y] == depth) {
    //             visited[cur.X][cur.Y] = 0;
    //         }
    //         cur.X += 1;
    //     }
    // }
    // else if(direction == 2) {
    //     cur.Y -= 1;
    //     while(cur.Y >= 0 && board[cur.X][cur.Y] != 6) {
    //         if(board[cur.X][cur.Y] == 0 && visited[cur.X][cur.Y] == depth) {
    //             visited[cur.X][cur.Y] = 0;
    //         }
    //         cur.Y -= 1;
    //     }
    // }
    // else if(direction == 3) {
    //     cur.X -= 1;
    //     while(cur.X >= 0 && board[cur.X][cur.Y] != 6) {
    //         if(board[cur.X][cur.Y] == 0 && visited[cur.X][cur.Y] == depth) {
    //             visited[cur.X][cur.Y] = 0;
    //         }
    //         cur.X -= 1;
    //     }
    // }
}

void backtracking(int depth, int cnt) {
    if(depth == cctvs.size()) {
        ans = min(ans, blind - cnt);
        return;
    }

    auto cctv = cctvs[depth];
    int type = board[cctv.X][cctv.Y];
    if(type == 1) {
        for(int i = 0; i < 4; i++) {
            int ret = visiting(i, cctv, depth + 1);

            backtracking(depth + 1, cnt + ret);

            unvisiting(i, cctv, depth + 1);
        }
    }
    else if(type == 2) {
        for(int i = 0; i < 2; i++) {
            int ret = visiting(i, cctv, depth + 1);
            ret += visiting(i + 2, cctv, depth + 1);

            backtracking(depth + 1, cnt + ret);

            unvisiting(i, cctv, depth + 1);
            unvisiting(i + 2, cctv, depth + 1);
        }
    }
    else if(type == 3) {
        for(int i = 0; i < 4; i++) {
            int ret = visiting(i, cctv, depth + 1);
            ret += visiting((i + 1) % 4, cctv, depth + 1);

            backtracking(depth + 1, cnt + ret);

            unvisiting(i, cctv, depth + 1);
            unvisiting((i + 1) % 4, cctv, depth + 1);
        }
    }
    else if(type == 4) {
        for(int i = 0; i < 4; i++) {
            int ret = visiting(i, cctv, depth + 1);
            ret += visiting((i + 1) % 4, cctv, depth + 1);
            ret += visiting((i + 2) % 4, cctv, depth + 1);

            backtracking(depth + 1, cnt + ret);

            unvisiting(i, cctv, depth + 1);
            unvisiting((i + 1) % 4, cctv, depth + 1);
            unvisiting((i + 2) % 4, cctv, depth + 1);
        }
    }
    else if(type == 5) {
        int ret = visiting(0, cctv, depth + 1);
        ret += visiting(1, cctv, depth + 1);
        ret += visiting(2, cctv, depth + 1);
        ret += visiting(3, cctv, depth + 1);

        backtracking(depth + 1, cnt + ret);

        unvisiting(0, cctv, depth + 1);
        unvisiting(1, cctv, depth + 1);
        unvisiting(2, cctv, depth + 1);
        unvisiting(3, cctv, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(1 <= board[i][j] && board[i][j] <= 5) 
                cctvs.push_back({i, j});
            else if(board[i][j] == 0) 
                blind++;
        }
    }

    backtracking(0, 0);

    cout << ans << '\n';
}