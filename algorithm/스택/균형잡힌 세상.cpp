#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		string str;
		getline(cin, str);
		if (str.compare(".") == 0)
			break;

		stack<char> s;
		bool valid = true;
		for (int i = 0; i < str.length() - 1; i++) {
			if (str[i] == '(' || str[i] == '[')
				s.push(str[i]);
			else if (str[i] == ')') {
				if (s.empty() || s.top() != '(') {
					valid = false;
					break;
				}
				s.pop();
			}
			else if (str[i] == ']') {
				if (s.empty() || s.top() != '[') {
					valid = false;
					break;
				}
				s.pop();
			}
		}
		if (!s.empty())
			valid = false;
		
		if (valid) 
			cout << "yes\n";
		else 
			cout << "no\n";
	}

	return 0;
}
