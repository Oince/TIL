#include <bits/stdc++.h>
using namespace std;

int L, C;
char input[20];
char arr[20];

bool is_vowel(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u')
        return true;

    return false;
}

void func(int depth, int start, bool vowel, int consonant) {
    if(depth == L) {
        if(vowel && consonant >= 2) {
            for(int i = 0; i < L; i++) {
                cout << arr[i];
            }
            cout << '\n';
        }
        return;
    }

    for(int i = start; i < C; i++) {
        arr[depth] = input[i];

        if(vowel) {
            if(is_vowel(arr[depth])) 
                func(depth + 1, i + 1, true, consonant);
            else
                func(depth + 1, i + 1, true, consonant + 1);
        }
        else {
            if(is_vowel(arr[depth])) 
                func(depth + 1, i + 1, true, consonant);
            else
                func(depth + 1, i + 1, false, consonant + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;
    for(int i = 0; i < C; i++) {
        cin >> input[i];
    }

    sort(input, input + C);
    func(0, 0, false, 0);
}