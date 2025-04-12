#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    stack<char> S;
    int sum = 0, num = 1;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            num *= 2;
            S.push(str[i]);
        }
        else if(str[i] == '[') {
            num *= 3;
            S.push(str[i]);
        }
        else if(str[i] == ')') {
            if(S.empty() || S.top() != '(') {
                cout << 0 << '\n';
                return 0;
            }

            if(str[i - 1] == '(')
                sum += num;
            S.pop();
            num /= 2;
        }
        else {
            if(S.empty() || S.top() != '[') {
                cout << 0 << '\n';
                return 0;
            }

            if(str[i - 1] == '[')
                sum += num;
            S.pop();
            num /= 3;
        }
    }

    if(S.empty()) 
        cout << sum;
    else 
        cout << 0;
}