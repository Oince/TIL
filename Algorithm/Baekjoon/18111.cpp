#include <iostream>
using namespace std;

int main() {
    int n, m, b, i, j, h, mintime = 2147483647, max = 0;
    cin >> n >> m >> b;

    int height[n][m];

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cin >> height[i][j];
            if(max < height[i][j]) {
                max = height[i][j];
            }
        }
    }

    for(h = max; h >= 0; h--) {
        int b_tmp = b;
        int time = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                int value = height[i][j] - h;
                if(value < 0) {
                    time += -value;
                    b_tmp -= -value;
                }
                else if(value > 0) {
                    time += 2 * value;
                    b_tmp += value;
                }
            }
        }

        //printf("h: %d, time: %d, b_tmp: %d, mintime: %d\n", h, time, b_tmp, mintime);
        if(b_tmp >= 0 && time < mintime) {
            mintime = time;
        }
        else if(time >= mintime) {
            break;
        }

    }

    cout << mintime << " " << h + 1 << '\n';

}