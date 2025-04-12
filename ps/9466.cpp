#include <bits/stdc++.h>
using namespace std;

int g[100005];

//0 방문 안함
//-1 사이클
//0보다 크면 해당 노드에서 출발해서 순회한거
int visited[100005];

void run(int start) {
    int cur = start;

    while(true) {
        //현재 노드 방문 기록에 시작 노드 번호 기록
        visited[cur] = start;
        //다음 노드로 넘어감
        cur = g[cur];

        //현재 노드의 기록이 시작 노드와 같다면 한바퀴 돌고 다시 왔다는거임
        //사이클이라는 뜻이니까 사이클에 속한다는 뜻인 -1로 방문 배열을 초기화하고 리턴함
        if(visited[cur] == start) {
            while(visited[cur] != -1) {
                visited[cur] = -1;
                cur = g[cur];
            }
            return;
        }
        //0이 아니면 방문했다는 뜻
        //바로 리턴
        else if(visited[cur] != 0) 
            return;

        //아무것도 아니면 다음 노드 방문

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, ans = 0;
        cin >> n;

        for(int i = 1; i <= n; i++) {
            cin >> g[i];
        }

        fill(visited + 1, visited + n + 1, 0);

        //방문하지 않았으면 순회함
        for(int i = 1; i <= n; i++) {
            if(visited[i] == 0)
                run(i);
        }

        //-1이 아닌 노드의 개수를 세면 그게 정답임
        for(int i = 1; i <= n; i++) {
            if(visited[i] != -1) 
                ans++;
        }

        cout << ans << '\n';
    }
}