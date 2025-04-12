#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    vector<int> v;
    cin >> n >> k;

    list<int> L;
    for(int i = 1; i <= n; i++) {
        L.push_back(i);
    }

    auto iter = L.begin();

    while(!L.empty()) {
        for(int i = 0; i < k - 1; i++) {
            if(iter == L.end()) {
                iter = L.begin();
            }
            iter++;
        }
        if(iter == L.end()) {
            iter = L.begin();
        }
        v.push_back(*iter);
        iter = L.erase(iter);
    }

    string res;
    for(int i : v) {
        res.append(to_string(i));
        res.append(", ");
    }
    res = res.substr(0, res.length() - 2);
    cout << "<" << res << ">" << '\n';
}