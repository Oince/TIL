#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int tanghuru[n];
    for(auto& i : tanghuru) {
        cin >> i;
    }

    int start = 0, end, count = 1, res = 0;
    int fruit[10] = {0};
    fruit[tanghuru[0]]++;
    for(end = 1; end < n; end++) {
        if(fruit[tanghuru[end]] > 0) {
            //아무것도 안함
        }
        else if(count < 2 && fruit[tanghuru[end]] == 0) {
            count++;
        }
        else {
            if(res < end - start) {
                res = end - start;
            }
            for(;start < end - 1; start++) {
                if(--fruit[tanghuru[start]] == 0) {
                    start++;
                    break;
                }
            }
        }
        
        fruit[tanghuru[end]]++;
    }
    if(res < end - start) {
        res = end - start;
    }

    cout << res << '\n';

    return 0;
}