#include <bits/stdc++.h>
using namespace std;

int ans = 0;

char input[5][5];
bool selected[25];
vector<pair<int, int>> v;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool bfs() {
    bool visited[5][5];
    bool selected_map[5][5];
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            visited[i][j] = 0;
            selected_map[i][j] = 0;
        }
    }

    for(auto cur : v) {
        selected_map[cur.first][cur.second] = 1;
    }

    queue<pair<int, int>> q;
    q.push(v.front());
    visited[v.front().first][v.front().second] = 1;

    int cnt = 1, s_cnt = 0;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        if(input[cur.first][cur.second] == 'S')
            s_cnt++;

        if(cnt == 7 && s_cnt >= 4) {
            return true;
        }

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) 
                continue;

            if(visited[nx][ny] == 0 && selected_map[nx][ny] == 1) {
                q.push({nx, ny});
                visited[nx][ny] = 1;
                cnt++;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> input[i][j];
        }
    }

    for(int i = 7; i < 25; i++) {
        selected[i] = 1;
    }

    //1. 조합을 사용해서 25개의 자리 중 7개를 선정
    //2. 각각의 자리가 연결되어 있고, s_cnt가 4 이상인지 확인
    do {
        for(int i = 0; i < 25; i++) {
            if(selected[i] == 0) {
                int x = i / 5;
                int y = i % 5;
                v.push_back({x, y});
            }
        }

        if(bfs()) {
            ans++;
        }
        v.clear();
    } while(next_permutation(selected, selected + 25));

    cout << ans << '\n';
    
}