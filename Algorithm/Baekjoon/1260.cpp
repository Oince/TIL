#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>> &g, int *visited, int r) {

    cout << r << " ";
    visited[r] = 1;
    for(int i = 0; i < g[r].size(); i++) {
        if(visited[g[r][i]] == 0) {
            dfs(g, visited, g[r][i]);
        }
    }
}

void bfs(vector<vector<int>> &g, int *visited, int r) {
    queue<int> q;

    cout << r << " ";
    visited[r] = 1;
    q.push(r);
    
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(int i = 0; i < g[v].size(); i++) {
            if(visited[g[v][i]] == 0) {
                cout << g[v][i] << " ";
                visited[g[v][i]] = 1;
                q.push(g[v][i]);
            }
        }
    }
}


int main() {
    int n, m, r, i;
    cin >> n >> m >> r;

    vector<vector<int>> g(n + 1, vector<int>());
    int visited[n + 1] = {0};

    for(i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }

    dfs(g, visited, r);
    cout << '\n';

    for(i = 0; i <= n; i++) {
        visited[i] = 0;
    }

    bfs(g, visited, r);
    cout << '\n';
}