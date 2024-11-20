#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        map[u][v] = 1;
        map[v][u] = 1;
    }

    queue<int> q;

    int min = 1000000000;
    int res = 0;
    for(int i = 1; i <= n; i++) {
        vector<int> visited(n + 1, 0);
        q.push(i);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(int j = 1; j <= n; j++) {
                if(j != i && map[cur][j] == 1 && visited[j] == 0) {
                    q.push(j);
                    visited[j] = visited[cur] + 1;
                }
            }
        }

        int tmp = 0;
        for(int j = 1; j <= n; j++) {
            tmp += visited[j];
        }

        if(min > tmp) {
            res = i;
            min = tmp;
        }

    }

    cout << res << '\n';
}