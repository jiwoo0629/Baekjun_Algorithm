#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	stack<long long> s;
	int N;
	cin >> N;

	long long sum = 0;
	long long num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		while (!s.empty() && s.top() <= num)
			s.pop();
		sum += s.size();
		s.push(num);
	}	
	
	cout << sum;

	return 0;
}

/* 배열을 이용한 방식 (시간초과)
#include <bits/stdc++.h>
using namespace std;

const int MX = 80001;
int building[MX];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	long long sum = 0;
	long long num;
	for (int i=0; i < N; i++) {
		cin >> num;
		building[i] = num;
	}
	
	for (int i = N - 1; i >= 0; i--) {
		for (int j = i + 1; j <= N; j++) {
			if (building[i] <= building[j])
				break;
			else 
				sum++;
		}
	}
	cout << sum;

	return 0;
}
*/
