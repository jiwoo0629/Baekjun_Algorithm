#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	deque<pair<int,int>> dq; //들어온 숫자들을 오름차순으로 정렬
	int N, L;
	cin >> N >> L;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;

		while (!dq.empty() && dq.back().second >= num)
			dq.pop_back();
		dq.push_back(make_pair(i, num)); //새로운 숫자가 맨 뒤로 가도록 함

		if (dq.front().first <= i - L) //L개의 숫자 중 최솟값을 구하기 위해, 나머지 숫자들은 덱에서 제거
			dq.pop_front();

		cout << dq.front().second << " ";
	}

	return 0;
}
