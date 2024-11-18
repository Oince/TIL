#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t > 0) {
        int l;
        pair<int, int> dep, dest;
        cin >> l;
        cin >> dep.first >> dep.second;
        cin >> dest.first >> dest.second;

        int visited[l][l];
        memset(visited, 0, sizeof(visited));
        queue<pair<int, int>> q;

        visited[dep.first][dep.second] = 1;
        q.push(dep);

        while(!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();
            int x = cur.first;
            int y = cur.second;
            if(x == dest.first && y == dest.second) {
                cout << visited[cur.first][cur.second] - 1 << '\n';
                break;
            }

            if(x - 2 >= 0 && y - 1 >= 0 && visited[x - 2][y - 1] == 0) {
                q.push(make_pair(x - 2, y - 1));
                visited[x - 2][y - 1] = visited[x][y] + 1;
            }

            if(x - 2 >= 0 && y + 1 < l && visited[x - 2][y + 1] == 0) {
                q.push(make_pair(x - 2, y + 1));
                visited[x - 2][y + 1] = visited[x][y] + 1;
            }

            if(x - 1 >= 0 && y + 2 < l && visited[x - 1][y + 2] == 0) {
                q.push(make_pair(x - 1, y + 2));
                visited[x - 1][y + 2] = visited[x][y] + 1;
            }

            if(x - 1 >= 0 && y - 2 >= 0 && visited[x - 1][y - 2] == 0) {
                q.push(make_pair(x - 1, y - 2));
                visited[x - 1][y - 2] = visited[x][y] + 1;
            }

            if(x + 1 < l && y + 2 < l && visited[x + 1][y + 2] == 0) {
                q.push(make_pair(x + 1, y + 2));
                visited[x + 1][y + 2] = visited[x][y] + 1;
            }

            if(x + 1 < l && y - 2 >= 0 && visited[x + 1][y - 2] == 0) {
                q.push(make_pair(x + 1, y - 2));
                visited[x + 1][y - 2] = visited[x][y] + 1;
            }

            if(x + 2 < l && y + 1 < l && visited[x + 2][y + 1] == 0) {
                q.push(make_pair(x + 2, y + 1));
                visited[x + 2][y + 1] = visited[x][y] + 1;
            }

            if(x + 2 < l && y - 1 >= 0 && visited[x + 2][y - 1] == 0) {
                q.push(make_pair(x + 2, y - 1));
                visited[x + 2][y - 1] = visited[x][y] + 1;
            }
        } 
        t--;
    }
}