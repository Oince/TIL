#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, i;
    vector<int> vec;
    vector<int> copy;
    
    cin >> n;
    for(i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
        copy.push_back(tmp);
    }

    sort(copy.begin(), copy.end());

    vector<int>::iterator copy_end = unique(copy.begin(), copy.end());
    
    for(int item : vec) {
        cout << lower_bound(copy.begin(), copy_end, item) - copy.begin() << " ";
    }
}