#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
    map<string, int> m;
    string name;
    int cnt = 0;
    cout << fixed;
    cout.precision(4);
    while(getline(cin, name)) {
        m[name]++;
        cnt++;
    }
    for(auto nxt : m) 
        cout << nxt.first << " " << (double)nxt.second / cnt * 100 << "\n";
    return 0;
}
