#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(vector<int> *g, int *visited, int r) {
    queue<int> q;
    int cnt = 0;

    visited[r] = ++cnt;
    q.push(r);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : g[u]) {
            if(visited[v] == 0) {
                visited[v] = ++cnt;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> g[n + 1];
    int visited[n + 1] = {0};

    int i;
    for(i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end(), greater<int>());
    }

    bfs(g, visited, r);

    for(i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }
}