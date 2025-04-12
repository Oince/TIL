#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int visited[100001] = {0};

    queue<int> q;
    q.push(n);
    visited[n] = 1;

    if(n >= k) {
        cout << n - k << '\n';
        return 0;
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        int depth = visited[cur];
        if(cur < 0 || cur > 100000 || visited[cur] < 1)
            continue;
        if(cur == k) {
            cout << depth - 1 << '\n';
            break;
        }
        cout << cur << " " << depth << '\n';

        q.push(cur - 1);
        visited[cur - 1] = depth + 1;
        q.push(cur + 1);
        visited[cur + 1] = depth + 1;
        q.push(cur * 2);
        visited[cur * 2] = depth + 1;

    }
}