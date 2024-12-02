#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;

    while(n--) {
        string str;
        cin >> str;

        stack<char> S;
        for(int i = 0; i < str.length(); i++) {
            if(!S.empty() && str[i] == S.top()) {
                S.pop();
            }
            else {
                S.push(str[i]);
            }
        }

        if(S.empty()) {
            ans++;
        }
    }
    cout << ans << '\n';
}