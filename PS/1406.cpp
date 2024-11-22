#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;
    string str;
    list<char> l;
    getline(cin, str);
    for(char c : str) {
        l.push_back(c);
    }
    auto iter = l.end();

    cin >> m;
    while(m--) {
        char command;
        cin >> command;
        if(command == 'L') {
            if(iter != l.begin())
                iter--;
        }
        else if(command == 'D') {
            if(iter != l.end())
                iter++;
        }
        else if(command == 'B') {
            if(iter != l.begin()) {
                iter--;
                iter = l.erase(iter)
            }
        }
        else {
            char c;
            cin >> c;
            l.insert(iter, c);
        }
    }

    for(char c : l) {
        cout << c;
    }

    

}