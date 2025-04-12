#include <iostream>
#include <deque>
#include <string>
#include <sstream>
using namespace std;

int ac(string& command, deque<int>& input) {
    bool isreverse = false;
    for(int i = 0; i < command.length(); i++) {

        if(command[i] == 'R') 
            isreverse = !isreverse;
        else {
            if(input.empty()) 
                return -1;
            
            if(isreverse) 
                input.pop_back();
            else 
                input.pop_front();
        }
    }

    if(isreverse)
        return 1;
    else
        return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t > 0) {
        string command;
        int n;
        deque<int> input;
        
        string tmp;
        cin >> command;
        cin >> n;
        cin >> tmp;

        tmp = tmp.substr(1, tmp.length() - 2);
        istringstream iss(tmp);
        string buffer;

        while(getline(iss, buffer, ',')) {
            input.push_back(stoi(buffer));
        }

        int ret = ac(command, input);

        if(ret == -1)
            cout << "error";
        else if(ret == 0) {
            cout << "[";
            for(auto iter = input.begin(); iter != input.end(); iter++) {
                if(iter + 1 == input.end())
                    cout << *iter;
                else 
                    cout << *iter << ",";
            }
            cout << "]";
        }
        else {
            cout << "[";
            for(auto iter = input.rbegin(); iter != input.rend(); iter++) {
                if(iter + 1 == input.rend())
                    cout << *iter;
                else 
                    cout << *iter << ",";
            }
            cout << "]";
        }

        cout << '\n';
        t--;
    }
}