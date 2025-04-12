#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> time_table(n);

    for(int i = 0; i < n; i++) {
        cin >> time_table[i].first >> time_table[i].second;
    }

    sort(time_table.begin(), time_table.end(), compare);

    int tmp = time_table[0].second;
    int res = 1;
    for(int i = 1; i < n; i++) {
        if(tmp <= time_table[i].first) {
            tmp = time_table[i].second;
            res++;
        }
    }

    cout << res << '\n';

}