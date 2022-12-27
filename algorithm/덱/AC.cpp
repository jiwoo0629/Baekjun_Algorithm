#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		deque<int> dq;

		string cmd;
		cin >> cmd;
		int n;
		cin >> n;
		string arr;
		cin >> arr;
		char num[3] = " ";
		int idx = 0;
		for (int j = 0; j < arr.length(); j++) {
			if (arr[j] >= '0' && arr[j] <= '9')
				num[idx++] = arr[j];
			if (arr[j] == ',' && idx != 0) {
				dq.push_back(atoi(num));
				for (int k = 0; k < idx; k++)
					num[k] = 0;
				idx = 0;
			}
			if (arr[j] == ']' && idx != 0)
				dq.push_back(atoi(num));
		}

		int error = 0;
		for (int j = 0; j < cmd.length(); j++) {
			if (cmd[j] == 'R') {
				reverse(dq.begin(), dq.end());
			}
			if (cmd[j] == 'D') {
				if (!dq.empty())
					dq.pop_front();
				else {
					error = 1;
					break;
				}
			}
		}

		if (error == 1)
			cout << "error\n";
		else {
			cout << "[";
			if (dq.empty())
				cout << "]\n";
			else {
				for (int j = 0; j < dq.size(); j++) {
					cout << dq[j];
					if (j == dq.size() - 1)
						cout << "]\n";
					else
						cout << ",";
				}
			}
		}
		dq.clear();
	}

	return 0;
}
