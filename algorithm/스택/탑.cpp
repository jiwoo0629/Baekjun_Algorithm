#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	stack<pair<int,int>> s;
	s.push({ 0, 100000001 });

	int N;
	cin >> N;
	
	int num;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		while (s.top().second < num)
			s.pop();
		cout << s.top().first << " ";
		s.push({ i, num });
	}
	return 0;
}
