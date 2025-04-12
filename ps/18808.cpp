#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int r, c;
int ans = 0;
int sticker[12][12];

int board[41][41];

bool pastable(int x, int y) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(board[i + x][j + y] == 1 && sticker[i][j] == 1)
                return false;
        }
    }
    return true;
}

void rotate() {
    int tmp[12][12];
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 12; j++) {
            tmp[i][j] = sticker[i][j];
        }
    }

    //배열 오른쪽으로 90도 돌리기 공식
    //돌린배열[i][j] = 원본배열[행의 최댓값 - 1 - j][i];
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            sticker[i][j] = tmp[r-1-j][i];
        }
    }
    swap(r, c);
}

void paste(int x, int y) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(sticker[i][j] == 1) {
                board[i + x][j + y] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    while(k--) {
        cin >> r >> c;
        for(int x = 0; x < r; x++) {
            for(int y = 0; y < c; y++) {
                cin >> sticker[x][y];
            }
        }

        for(int cnt = 0; cnt < 4; cnt++) {
            bool flag = false;
            //여기서 board 범위 밖으로 벗어나지 않도록 
            //n-r, m-c 까지만 돔
            for(int i = 0; i <= n - r; i++) {
                if(flag) 
                    break;
                for(int j = 0; j <= m - c; j++) {
                    if(!flag && pastable(i, j)) {
                        paste(i, j);
                        flag = true;
                        break;
                    }
                }
            }
            if(flag)
                break;

            rotate();
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 1)
                ans++;
        }
    }

    cout << ans << '\n';

}