#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<int> v(n + 1);
    v[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for(int i = 2; i <= n; i++) {
        v[i] = v[i - 1] + v[i];
    }

    while(m > 0) {
        int i, j;
        cin >> i >> j;

        cout << v[j] - v[i - 1] << '\n';
        m--;
    }

}