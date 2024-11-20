#include <iostream>
using namespace std;

bool is_digit(string s) {
    for(int i = 0; i < s.length(); i++) {
        if(!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

void fizzbuzz(int n) {
    if(n % 15 == 0)
        cout << "FizzBuzz\n";
    else if(n % 5 == 0)
        cout << "Buzz\n";
    else if(n % 3 == 0)
        cout << "Fizz\n";
    else
        cout << n << '\n'; 
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    if(is_digit(s1)) {
        int n = stoi(s1);
        fizzbuzz(n + 3);
    }
    else if(is_digit(s2)) {
        int n = stoi(s2);
        fizzbuzz(n + 2);
    }
    else {
        int n = stoi(s3);
        fizzbuzz(n + 1);
    }
    return 0;


}