#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

#define MAX 1000001
int n, idx = 0, num[MAX], d[MAX], p[MAX]; //d : i번째 수가 dp에 있었던 위치, p : i번째 수 앞에 있어야 하는 수의 idx
pair<int, int> dp[MAX]; //숫자, 인덱스
stack<int> s;

int lower_bound(int start, int end, int k) {
	if (start == end) return start;
	int mid = (start + end) / 2;
	if (dp[mid].first >= k)  //이번 숫자가 mid의 숫자보다 작거나 같으면
		return lower_bound(start, mid, k);
	else
		return lower_bound(mid + 1, end, k);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		p[i] = -1; //i번째 수 앞에 있어야 하는 수의 idx
	}
	dp[0] = { num[0], 0 };

	for (int i = 1; i < n; i++) {
		if (num[i] > dp[idx].first) { //이 값이 부분 수열의 마지막 값보다 크면, 뒤에 삽입
			p[i] = dp[idx].second;
			dp[++idx] = { num[i], i };
			d[i] = idx;
		}
		else if(num[i] < dp[idx].first) { //아닐 경우, 이 숫자의 lower_bound에 있는 숫자를 대치한다.
			int k = lower_bound(0, idx, num[i]);
			if(k != 0) p[i] = dp[k - 1].second;
			dp[k] = { num[i], i };
			d[i] = k;
		}
	}
	stack<int> s;
	int cur = find(d, d + n, idx) - d;
	while (p[cur] != -1) {
		s.push(num[cur]);
		cur = p[cur];
	}
	s.push(num[cur]);
	cout << s.size() << "\n";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}
