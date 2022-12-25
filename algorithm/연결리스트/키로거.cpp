#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        list<char> l = {};
        string s;
        cin >> s;
        list<char>::iterator iter = l.begin();
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '<') {
                if (iter != l.begin())
                    iter--;
            }
            else if (s[j] == '>') {
                if (iter != l.end())
                    iter++;
            }
            else if (s[j] == '-') {
                if (iter != l.begin()) {
                    iter--;
                    iter = l.erase(iter);
                }
            }
            else {
                l.insert(iter, s[j]);
            }
        }
        for (list<char>::iterator it = l.begin(); it != l.end(); it++)
            cout << *it;
        cout << endl;
    }

    return 0;
}
