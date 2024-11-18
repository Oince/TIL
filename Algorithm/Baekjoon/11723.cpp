#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;

    int set[21] ={0};


    while(m > 0) {
        string cmd;
        int x;
        cin >> cmd;

        if(cmd.compare("add") == 0) {
            cin >> x;
            set[x] = 1;
        }
        else if(cmd.compare("remove") == 0) {
            cin >> x;
            set[x] = 0;
        }
        else if(cmd.compare("check") == 0) {
            cin >> x;
            if(set[x] == 1) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if(cmd.compare("toggle") == 0) {
            cin >> x;
            if(set[x] == 1) {
                set[x] = 0;
            }
            else {
                set[x] = 1;
            }
        }
        else if(cmd.compare("all") == 0) {
            for(int i = 1; i <= 20; i++) {
                set[i] = 1;
            }
        }
        else if(cmd.compare("empty") == 0) {
            for(int i = 1; i <= 20; i++) {
                set[i] = 0;
            }
        }
        m--;
    }
}