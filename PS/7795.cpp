#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> v;
        
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.push_back({a, 0});
        }
        for(int i = 0; i < m; i++) {
            int b;
            cin >> b;
            v.push_back({b, 1});
        }

        sort(v.begin(), v.end());

        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < v.size(); i++) {
            if(v[i].second == 0) 
                ans += cnt;
            else 
                cnt++;
        }

        cout << ans << '\n';
    }
}