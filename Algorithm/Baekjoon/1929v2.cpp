#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    bool prime[1000001];
    prime[1] = true;

    for(int i = 2; i <= 1000; i++) {
        if(!prime[i]) {
            for(int j = i * 2; j <= 1000000; j += i) {
                prime[j] = true;
            } 
        }
    }

    for(int i = m; i <= n; i++) {
        if(!prime[i])
            cout << i << '\n';
    }
}