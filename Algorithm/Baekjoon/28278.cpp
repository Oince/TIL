#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;
    
    int n, command;

    cin >> n;

    while(n > 0) {
        cin >> command;

        if(command == 1) {
            int input;
            cin >> input;
            s.push(input);
        }
        else if(command == 2) {
            if(s.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << s.top() << '\n';
                s.pop();
            }
        }
        else if(command == 3) {
            cout << s.size() << '\n';
        }
        else if(command == 4) {
            cout << s.empty() << '\n';
        }
        else if(command == 5) {
            if(!s.empty()) {
                cout << s.top() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
        n--;
    }

    return 0;

}
