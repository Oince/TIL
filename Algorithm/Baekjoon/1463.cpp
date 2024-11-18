#include <iostream>
#include <queue>
using namespace std;

int visited[1000001] = {0};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;

    cin >> n;

    queue<int> q;
    q.push(n);
    visited[n] = 1;

    while(!q.empty()) {
        int cur = q.front(); q.pop();

        if(cur == 1) {
            break;
        }
        
        if(cur % 3 == 0 && visited[cur / 3] < 1) {
            q.push(cur / 3);
            visited[cur / 3] = visited[cur] + 1;
        }

        if(cur % 2 == 0 && visited[cur / 2] < 1) {
            q.push(cur / 2);
            visited[cur / 2] = visited[cur] + 1;
        }

        if(visited[cur - 1] < 1) {
            q.push(cur - 1);
            visited[cur - 1] = visited[cur] + 1;
        }
    }

    cout << visited[1] - 1 << '\n';
}