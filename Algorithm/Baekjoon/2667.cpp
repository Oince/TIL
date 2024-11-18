#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[25][25];
int visited[25][25];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int cnt = 0;
int n = 0;

void dfs(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n)
            continue;

        if(visited[nx][ny] == 0 && map[nx][ny] == 1) {
            visited[nx][ny] = 1;
            cnt++;
            dfs(nx, ny);
        }
    }

}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) {
            map[i][j] = s[j] - '0';
            visited[i][j] = 0;
        }
    }

    vector<int> res;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] == 1 && visited[i][j] == 0) {
                visited[i][j] = 1;
                cnt = 1;
                dfs(i, j);
                res.push_back(cnt);
            }
        }
    }
    
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for(int i : res) {
        cout << i << '\n';
    }
}