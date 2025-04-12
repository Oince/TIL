#include <bits/stdc++.h>
using namespace std;

int visited[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    fill(visited, visited + 100001, -1);

    queue<int> q;
    q.push(n);
    visited[n] = 0;

    while(!q.empty()) {
        int cur = q.front(); q.pop();

        if(cur == k) 
            break;

        int back = cur - 1;
        int forward = cur + 1;
        int teleport = cur * 2;

        if(back >= 0 && visited[back] == -1) {
            q.push(back);
            visited[back] = visited[cur] + 1;
        }

        if(forward <= 100000 && visited[forward] == -1) {
            q.push(forward);
            visited[forward] = visited[cur] + 1;
        }

        if(teleport <= 100000 && visited[teleport] == -1) {
            q.push(teleport);
            visited[teleport] = visited[cur] + 1;
        }
    }

    cout << visited[k] << '\n';
}