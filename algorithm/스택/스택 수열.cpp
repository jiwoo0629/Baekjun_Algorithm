#include <bits/stdc++.h>
using namespace std;

int main(void) {
	stack<int> s;
	int N;
	cin >> N;

	int count = 1;
	vector<char> v;
	for (int i = 0; i < N; i++) {
		int num; 
		cin >> num;
		while (count <= num) {
			s.push(count++);
			v.push_back('+');
		}
		if (s.top() != num) {
			cout << "NO";
			return 0;
		}
		s.pop();
		v.push_back('-');
	}
	
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}
