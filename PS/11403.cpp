#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    int map[n][n];
    int res[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for(int v = 0; v < n; v++) {
        queue<int> q;
        int visited[n] = {0};
        q.push(v);

        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(int i = 0; i < n; i++) {
                if(map[cur][i] == 1 && visited[i] == 0) {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(visited[i] == 1) {
                res[v][i] = 1;
            }
            else {
                res[v][i] = 0;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << '\n';
    }



    return 0;
}