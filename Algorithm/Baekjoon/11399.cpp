#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, time = 0, res = 0;
    int *p;

    cin >> n;
    p = new int[n];
    for(i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(p, p + n);

    for(i = 0; i < n; i++) {
        res += p[i]*(n - i);
    }

    cout << res;
    return 0;
}