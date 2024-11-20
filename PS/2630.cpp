#include <iostream>
using namespace std;

int paper[128][128];
int white = 0;
int blue = 0;

int rec(int x, int y, int n) {
    if(n == 1) {
        if(paper[x][y] == 0) {
            return 0;
        }
        else {
            return 1;
        }
    }

    int ret[4];

    ret[0] = rec(x, y, n / 2);
    ret[1] = rec(x + n / 2, y, n / 2);
    ret[2] = rec(x, y + n / 2, n / 2);
    ret[3] = rec(x + n / 2, y + n / 2, n / 2);

    int a = ret[0] & ret[1] & ret[2] & ret[3];
    int o = ret[0] | ret[1] | ret[2] | ret[3];

    if(a == 1) {
        return 1;
    }
    else if(o == 0) {
        return 0;
    }
    else {
        for(int i = 0; i < 4; i++) {
            if(ret[i] == 0) {
                white++;
            }
            else if(ret[i] == 1) {
                blue++;
            }
        }
        return 2;
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }

    int ret = rec(0, 0, n);
    if(ret == 0) {
        white++;
    }
    else if(ret == 1) {
        blue++;
    }
    cout << white << '\n';
    cout << blue << '\n';

}