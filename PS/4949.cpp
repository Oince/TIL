#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        string str;
        getline(cin, str);
        if(str[0] == '.') {
            break;
        }

        stack<char> S;
        bool ans = true;

        for(char c : str) {
            if(c == '(' || c == '[') {
                S.push(c);
            }
            else if(c == ')') {
                if(S.empty() || S.top() != '(') {
                    ans = false;
                    break;
                }
                S.pop();
            }
            else if(c == ']') {
                if(S.empty() || S.top() != '[') {
                    ans = false;
                    break;
                }
                S.pop();
            }
        }

        if(!S.empty())
            ans = false;

        if(ans)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
}