#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, i, tmp = 0;
    cin >> n;
    int arr[n];
    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> stk(n);
    stk.push_back(arr[n - 1]);
    arr[n - 1] = -1;

    for(i = n - 2; i >= 0; i--) {
        tmp = arr[i];
        while(!stk.empty()) {
            if(arr[i] < stk.back()) {
                arr[i] = stk.back();
                break;
            }
            else {
                stk.pop_back();
            }
        }

        if(stk.empty()) {
            arr[i] = -1;
        }
        stk.push_back(tmp);

    }

    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

}