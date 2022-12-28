#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int goodword = 0;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		stack<char> s;
		for (int j = 0; j < str.length(); j++) {
			if (s.empty() || s.top() != str[j])
				s.push(str[j]);
			else if (str[j] == s.top())
				s.pop();
		}
		if (s.empty())
			goodword++;
	}
	cout << goodword;

	return 0;
}
