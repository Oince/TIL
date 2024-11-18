#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int g[n + 1][n + 1];
    memset(g, 0, sizeof(g));
    int i;
    for(i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }

    int visited[n + 1] = {0};
    queue<int> q;

    visited[1] = 1;
    q.push(1);

    int res = 0;
    while(!q.empty()){
        int r = q.front(); q.pop();
        for(i = 1; i <= n; i++) {
            if(visited[i] == 0 && g[r][i] == 1) {
                visited[i] = 1;
                q.push(i);
                res++;
            }
        }
    }

    cout << res << '\n';
}