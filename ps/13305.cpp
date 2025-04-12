#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, i;
    long res, minvalue = 0;
    cin >> n;
    int *length = new int[n - 1];
    int *value = new int[n];
    
    for(i = 0; i < n - 1; i++) {
        cin >> length[i];
    }
    for(i = 0; i < n; i++) {
        cin >> value[i];
    }

    i = 0;
    minvalue = value[i];
    res += minvalue * length[i];

    for(i = 1; i < n - 1; i++) {
        minvalue = min(minvalue, (long)value[i]);
        res += minvalue * length[i];
    }

    // i = 1;
    // j = 0;
    // while(i < n) {
    //     tmp += length[i - 1];
    //     if(i == n - 1) {
    //         res += value[j] * tmp;
    //         break;
    //     }
    //     else if(value[j] < value[i]) {
    //         i++;
    //     }
    //     else if (value[j] >= value[i]){
    //         res += value[j] * tmp;
    //         j = i;
    //         i++;
    //         tmp = 0;
    //     }
    // }

    cout << res;
}