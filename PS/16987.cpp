#include <bits/stdc++.h>
using namespace std;

int n, ans;

struct Egg {
    int hp;
    int weight;
};

Egg egg[10];

void func(int depth) {
    if(depth == n) {
        return;
    }

    for(int i = 0; i < n; i++) {
        // cout << "depth: " << depth << " i: " << i << '\n';
        if(egg[depth].hp <= 0) {
            // cout << "call iffunc(" << depth + 1 << ")\n";
            func(depth + 1);
        }
        else if(depth == i || egg[i].hp <= 0) {
            // cout << "continue\n";
            continue;
        }
        else {
            egg[i].hp -= egg[depth].weight;
            egg[depth].hp -= egg[i].weight;
            // cout << "call elsefunc(" << depth + 1 << ")\n";
            func(depth + 1);
            egg[i].hp += egg[depth].weight;
            egg[depth].hp += egg[i].weight;
        }
    }

    int tmp = 0;
    for(int i = 0; i < n; i++) {
        if(egg[i].hp <= 0)
            tmp++;
    }
    // cout << "tmp: " << tmp << '\n';
    ans = max(ans, tmp);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> egg[i].hp >> egg[i].weight;
    }

    func(0);
    
    cout << ans << '\n';




}