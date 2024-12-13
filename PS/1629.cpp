#include <bits/stdc++.h>
using namespace std;

int a, b, c;

long long pow(int a, int b, int c) {

    if (b == 1) 
        return a % c;

    long long val = pow(a, b / 2, c);
    val = val * val % c;

    if(b % 2 == 0) 
        return val;
    else
        return val * a % c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    cout << pow(a, b, c) << '\n';
}