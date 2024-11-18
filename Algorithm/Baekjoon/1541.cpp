#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int i, j = 0, res = 0;
    bool flag = true;
    for(i = 0; i <= s.size(); i++) {
        if(!isdigit(s[i]) || s[i] == '\0') {
            if(flag)
                res += stoi(s.substr(j, i - j));
            else
                res -= stoi(s.substr(j, i - j));
            j = i + 1;
            if(s[i] == '-') 
                flag = false;
        }
    }
    cout << res;
}