#include <iostream>
#include <queue>
using namespace std;

int main() {
    int testcase, n, m, i, tmp, res = 0;

    cin >> testcase;
    while(testcase > 0) {
        cin >> n >> m;
        priority_queue<int> priority;
        queue<pair<int, int>> position;
        for(i = 0; i < n; i++) {
            cin >> tmp;
            priority.push(tmp);
            position.push(make_pair(i, tmp));
        }

        while(!position.empty()) {
            int pri = priority.top();
            pair<int, int> pos = position.front();
            position.pop();

            if(pos.second < pri) {
                position.push(pos);
            }
            else {
                priority.pop();
                res++;
                if(pos.first == m) {
                    break;
                }
            }
        }

        cout << res << '\n';
        res = 0;
        testcase--;
    }

}