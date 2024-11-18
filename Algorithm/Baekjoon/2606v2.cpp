#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int res = 0;

void dfs(vector<vector<int>> &g, int *visited, int r) {
    if(visited[r] > 0) {
        return;
    }
    visited[r] = 1;

    for(int i = 1; i <= g[r].capacity(); i++) {
        if(visited[i] == 0 && g[r][i] == 1) {
            res++;
            dfs(g, visited, i);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1, vector<int>(n + 1 , 0));
    int visited[n + 1] = {0};

    int i;
    for(i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }

    dfs(g, visited, 1);

    cout << res << '\n';

}