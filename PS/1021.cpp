#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
deque<int> dq;

void push_left() {
    dq.push_back(dq.front());
    dq.pop_front();
    ans++;
}

void push_right() {
    dq.push_front(dq.back());
    dq.pop_back();
    ans++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    while(m--) {
        int x;
        cin >> x;

        int i;
        for(i = 0; i < dq.size(); i++) {
            if(dq[i] == x) {
                break;
            }
        }

        int mid = dq.size() / 2;

        // cout << "i: " << i << '\n';
        // cout << "mid: " << mid << '\n';

        if(i <= mid) {
            for(int j = 0; j < i; j++) {
                push_left();
            }
        }
        else {
            for(int j = 0; j < dq.size() - i; j++) {
                push_right();
            }
        }

        dq.pop_front();
    }

    cout << ans << '\n';
}