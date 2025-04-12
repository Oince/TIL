#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    string str;
    cin >> str;

    stack<char> S;
    S.push(str[0]);

    for(int i = 1; i < str.length(); i++) {
        if(str[i] == ')') {
            S.pop();
            if(str[i - 1] == '(') {
                ans += S.size();
            }
            else {
                ans++;  
            }
        }
        else {
            S.push(str[i]);
        }
    }

    cout << ans << '\n';

}