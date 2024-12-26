#include <bits/stdc++.h>
using namespace std;

int initset[50];
int arr[50];
int k;

void func(int depth, int start) {
    if(depth == 6) {
        for(int i = 0; i < 6; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = start; i < k; i++) {
        arr[depth] = initset[i];
        func(depth + 1, i + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        cin >> k;

        if(k == 0) 
            break;

        for(int i = 0; i < k; i++) {
            cin >> initset[i];
        }

        func(0, 0);
        cout << '\n';

    }
}