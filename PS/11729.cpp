#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int dep, int via, int dest) {
    if(n == 1) {
        cout << dep << " " << dest << '\n';
    }
    else {
        hanoi(n - 1, dep, dest, via);
        cout << dep << " " << dest << '\n';
        hanoi(n - 1, via, dep, dest);
    }

}
int main()  {
    int n;
    cin >> n;

    cout << (int)pow(2, n) - 1 << '\n';

    hanoi(n, 1, 2, 3);
}