#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--) {
        string str;
        cin >> str;

        stack<char> S;
        bool is_vps = true;
        for(char c : str) {
            if(c == '(') {
                S.push(c);
            }
            else {
                if(S.empty() || S.top() != '(') {
                    is_vps = false;
                    break;
                }
                S.pop();
            }
        }

        if(!S.empty())
            is_vps = false;

        if(is_vps) 
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';

    }
}