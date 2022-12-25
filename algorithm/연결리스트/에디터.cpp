#include <bits/stdc++.h>
using namespace std;

int main(void) {
    list<char> l;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        l.push_back(s[i]);
    }
    
    int M;
    cin >> M;

    char cmd, c;
    list<char>::iterator iter = l.end();
    for (int i = 0; i < M; i++) {
        cin >> cmd;
        if(cmd == 'P') 
            cin >> c;
        if (cmd == 'L') {
            if(iter != l.begin())
                iter--;
        }  
        else if (cmd == 'D') {
            if (iter != l.end())
                iter++;
        }
        else if (cmd == 'B') {
            if (iter != l.begin()) {
                iter--;
                iter = l.erase(iter);
            }    
        }
        else if (cmd == 'P') {
            l.insert(iter, c);
        }
    }

    for (list<char>::iterator it = l.begin(); it != l.end(); it++)
        cout << *it;

    return 0;
}
