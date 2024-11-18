#include <iostream>
#include <vector>
using namespace std;

int res = 0;
int visited[1001];

void dfs(int n, vector<vector<int>> &g) {
    if(visited[n] > 0) {
       return;
    }

    visited[n] = 1;

    for(int i = 0; i < g[n].size(); i++) {
        dfs(g[n][i], g);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1; i<= n; i++) {
        if(visited[i] == 0) {
            res++;
        }
        dfs(i, g);
    }

    cout << res << '\n';

}