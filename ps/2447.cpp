#include <iostream>
using namespace std;

void star(int n, int i, int j) {
    if(n == 1) 
        cout << "*";    
    else if((i / (n / 3)) % 3 == 1 && (j / (n / 3)) % 3 == 1)
        cout << " ";
    else
        star(n / 3, i, j);
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            star(n, i, j);
        }
        cout << '\n';
    }
}