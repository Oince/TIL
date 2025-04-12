#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n, i;
    cin >> n;

    if(n == 0) {
        cout << 0;
        return 0;
    }

    int input[n];
    for(i = 0; i < n; i++) {
        cin >> input[i];
    }

    int cut = round(n * 0.15);
    sort(input, input + n);

    int sum = 0;
    for(i = cut; i < n - cut; i++) {
        sum += input[i];
    }

    cout << round(sum / (n - 2.0 * cut)) << '\n';

}