#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;

    cin >> n >> m;

    map<string, string> map;
    string domain, password;
    for(int i = 0; i < n; i++) {
        cin >> domain >> password;
        map.insert(make_pair(domain, password));
    }
    
    for(int i = 0; i < m; i++) {
        cin >> domain;
        cout << map[domain] << '\n';
    }
    

}