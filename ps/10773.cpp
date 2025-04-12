    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int k;
        cin >> k;

        vector<int> v;

        while(k--) {
            int n;
            cin >> n;
            if(n == 0) {
                v.pop_back();
            }
            else {
                v.push_back(n);
            }
        }

        int res = 0;
        for(int i : v) {
            res += i;
        }
        cout << res << '\n';
        
    }