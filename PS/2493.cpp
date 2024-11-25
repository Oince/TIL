#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int> tower;
    stack<pair<int, int>> S;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        tower.push_back(tmp);
    }

    for(int i = 0; i < n; i++) {
        while(!S.empty() && S.top().second < tower[i]) {
            S.pop(); 
        }

        if(S.empty()) 
            cout << "0 ";
        else 
            cout << S.top().first << " ";

        S.push(make_pair(i + 1, tower[i]));
    }

}