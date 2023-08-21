#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
    int sum = 0, num = 1;
    stack<char> s;
    string str;
    cin >> str;
    for(int i=0; i<str.size(); i++) {
        if(str[i] == '(') {
            s.push('(');
            num *= 2;
        }
        else if(str[i] == '[') {
            s.push('[');
            num *= 3;
        }    
        else if(str[i] == ')') {
            if(s.empty() || s.top() != '(') {
                cout << 0;
                return 0;
            }
            if(str[i-1] == '(') sum += num;
            s.pop();
            num /= 2;
        }
        else if(str[i] == ']') {
            if(s.empty() || s.top() != '[') {
                cout << 0;
                return 0;
            }
            if(str[i-1] == '[') sum += num;
            s.pop();
            num /= 3;
        }
    }
    if(s.empty()) cout << sum;
    else cout << 0;

    return 0;
}
