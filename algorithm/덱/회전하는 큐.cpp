#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	deque<int> dq;
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		dq.push_back(i);

	int sum = 0;
	int prev = 1;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		int idx = find(dq.begin(), dq.end(), x) - dq.begin(); //index 값
		while (dq.front() != x) {
			if (idx < dq.size() - idx) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			sum++;
		}
		dq.pop_front();
	}
	cout << sum;

	return 0;
}
