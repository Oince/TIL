#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n;
    vector<pair<int, int>> arr;
    int res[n];
    
    for(i = 0; i < n; i++) {
        pair<int, int> input;
        cin >> input.first;
        input.second = i;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());

    int count = -1, value = -1000000001;
    for(i = 0; i < n; i++) {
        if(value < arr[i].first) {
            count++;
            value = arr[i].first;
        }
        res[arr[i].second] = count;
    }

    for(i = 0; i < n; i++) {
        cout << res[i] << " ";
    }

}