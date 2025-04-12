#include <bits/stdc++.h>
using namespace std;

int visited[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    queue<int> q;
    visited[s] = 1;
    q.push(s);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        int next_up = cur + u;
        int next_down = cur - d;

        if(cur == g) {
            cout << visited[cur] - 1 << '\n';
            return 0;
        }

        if(next_up <= f && visited[next_up] == 0) {
            visited[next_up] = visited[cur] + 1;
            q.push(next_up);
        }

        if(next_down >= 1 && visited[next_down] == 0) {
            visited[next_down] = visited[cur] + 1;
            q.push(next_down);
        }
    }

    cout << "use the stairs\n";


}