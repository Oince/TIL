    #include <bits/stdc++.h>
    using namespace std;

    bool arr[2000001];

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n, x;
        cin >> n;
        int input[n];
        for(int i = 0; i < n; i++) {
            cin >> input[i];
        }
        cin >> x;

        int res = 0;
        for(int i = 0; i < n; i++) {
            if(x - input[i] > 0 && arr[x-input[i]]) {
                res++;
            }
            arr[input[i]] = true;
        }

        cout << res << '\n';
    }