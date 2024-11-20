#include <iostream>
using namespace std;

int main() {
    bool num[10001] = {0};
    int i;
    for(i = 1; i <= 10000; i++) {
        int s = 0, tmp = i;
        do {
            s += tmp % 10;
            tmp = tmp / 10;
        } while(tmp > 0);
        s += i;

        if(s <= 10000)
            num[s] = true;
    }

    for(i = 1; i <= 10000; i++) {
        if(!num[i]) 
            cout << i << '\n';
    }

}