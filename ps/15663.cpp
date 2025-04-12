#include <bits/stdc++.h>
using namespace std;

int n, m;
int input[10];

int arr[10];
bool visited[10];

void func(int depth) {
    if(depth == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    //중복 체크
    //사전순이기 때문에 이전 항과 현재 항이 같으면 중복임
    //tmp에 현재 항을 저장하고 다음 항 방문할 때 사용
    int tmp = 0;
    for(int i = 0; i < n; i++) {
        if(visited[i] == 0 && tmp != input[i]) {
            visited[i] = 1;
            tmp = arr[depth] = input[i];
            func(depth + 1);
            visited[i] = 0;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    sort(input, input + n);
    func(0);

}