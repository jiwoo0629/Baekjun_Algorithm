#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    return a < b;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<string> v;
    for(int i=0; i<s.length(); i++) {
        string str = "";
        for(int j=s.length() - 1 - i; j<s.length(); j++) str += s[j];
        v.push_back(str);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++) cout << v[i] << "\n";

    return 0;
}
