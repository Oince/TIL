#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int seq[n];
    for(int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    string ans;
    stack<int> s;
    int num = 1;

    for(int i = 0; i < n; i++) {
        while(num <= seq[i]) {
            s.push(num++);
            ans += "+\n";
        }

        if(s.top() == seq[i]) {
            s.pop();
            ans += "-\n";
        }
        else {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << ans;
    
}