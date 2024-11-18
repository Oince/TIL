#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(int r, vector<int> *g, int *visited) {
    static int cnt = 0;
    if(visited[r] > 0)
        return;

    visited[r] = ++cnt;   
    for(int i = 0; i < g[r].size(); i++) {
        if(visited[g[r][i]] == 0) {
            dfs(g[r][i], g, visited);
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r, i;
    cin >> n >> m >> r;

    vector<int> g[n];
    int visited[n] = {0,};

    for(i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    for(i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end(), greater<>());
    }

    dfs(r - 1, g, visited);

    for(i = 0; i < n; i++) {
        cout << visited[i] << '\n';
    }

    
}