#include <bits/stdc++.h>
using namespace std;

int paper[2200][2200];
int N;
int ans[3];

bool check(int n, int x, int y) {
    for(int i = x; i < x + n; i++) {
        for(int j = y; j < y + n; j++) {
            if(paper[x][y] != paper[i][j])
                return false;
        }
    }
    return true;
}

//다 나눈 다음에 계산하려 하지 말고 중간에 먼저 계산하고 안되면 재귀 호출하기
void func(int n, int x, int y) {

    if(check(n, x, y)) {
        ans[paper[x][y] + 1]++;
        return;
    }
    
    int split = n / 3;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            func(split, x + i*split, y + j*split);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    func(N, 0, 0);

    for(int i = 0; i < 3; i++) {
        cout << ans[i] << '\n';
    }

}