#include <iostream>
#include <algorithm>
using namespace std;

char chessboard[8][8] = {
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j, res = 65;
    cin >> n >> m;

    char **input = new char*[n];
    for(i = 0; i < n; i++) {
        input[i] = new char[m];
    }

    for(i = 0; i < n; i++) {
        cin >> input[i];
    }

    for(i = 0; i <= n - 8; i++) {
        for(j = 0; j <= m - 8; j++) {
            int count = 0;
            for(int k = i; k < i + 8; k++) {
                for(int l = j; l < j + 8; l++) {
                    if(input[k][l] != chessboard[k-i][l-j]) {
                        count++;
                    }
                }
            }
            count = min(count, 64 - count);
            res = min(res, count);
        }
    }

    cout << res << '\n';

    return 0;
}