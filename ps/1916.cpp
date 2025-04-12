#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(pair<int, int> p1, pair<int, int>p2) {
        return p1.second > p2.second;
    }
};

int main() {
    int n, m, dep, dest;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, -1));

    for(int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        if(graph[a][b] == -1 || graph[a][b] > cost)
            graph[a][b] = cost;

    }
    cin >> dep >> dest;

    vector<int> distance(n + 1, 100000000);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    distance[dep] = 0;
    pq.push(make_pair(dep, 0));

    while(!pq.empty()) {
        int cur_node = pq.top().first;
        int cur_dist = pq.top().second;
        pq.pop();

        for(int i = 1; i <= n; i++) {
            if(graph[cur_node][i] >= 0) {
                int next_dist = cur_dist + graph[cur_node][i];
                if(next_dist < distance[i]) {
                    distance[i] = next_dist;
                    pq.push(make_pair(i, next_dist));
                }
            }
        }
    }

    cout << distance[dest] << '\n';
    return 0;
}