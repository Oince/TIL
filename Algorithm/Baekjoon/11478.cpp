#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {

    string s;
    set<string> set;

    cin >> s;

    for(int i = 0; i < s.length(); i++) {
        for(int j = 1; j <= s.length() - i; j++) {
            set.insert(s.substr(i, j));
        }
    }

    cout << set.size() << '\n';
    return 0;
}