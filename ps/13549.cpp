#include <bits/stdc++.h>
using namespace std;

int visited[200001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({1, n});
    visited[n] = 1;
    while(!q.empty()) {
        pair<int, int> cur = q.top(); q.pop();

        if(cur.second == k)
            break;

        int teleport = cur.second * 2;
        int back = cur.second - 1;
        int forward = cur.second + 1;

        if(teleport <= 200000 && visited[teleport] == 0) {
            visited[teleport] = cur.first;
            q.push({visited[teleport], teleport});
        }

        if(back >= 0 && visited[back] == 0) {
            visited[back] = cur.first + 1;
            q.push({visited[back], back});
        }

        if(forward <= 200000 && visited[forward] == 0) {
            visited[forward] = cur.first + 1;
            q.push({visited[forward], forward});
        }
    }

    cout << visited[k] - 1 << '\n';
}