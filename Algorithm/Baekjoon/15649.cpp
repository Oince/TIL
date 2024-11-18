#include <iostream>
using namespace std;

int n, m;
bool visited[9] = {0};
int res[9] = {0};

void backtraking(int depth) {
    if(depth == m) {
        for(int i = 0; i < m; i++) {
            cout << res[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(visited[i] == false) {
            visited[i] = true;
            res[depth] = i;
            backtraking(depth + 1);
            visited[i] = false;
        } 
    }
}

int main() {
    cin >> n >> m;
    backtraking(0);
}