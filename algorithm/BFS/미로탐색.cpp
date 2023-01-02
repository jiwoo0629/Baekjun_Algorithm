#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool vis[102][102];
int step[102][102] = { 0, };

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> n >> m;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	queue<pair<int, int>> q;
	vis[0][0] = true;
	q.push({ 0,0 });
	step[0][0] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int row = cur.first + dy[k];
			int col = cur.second + dx[k];
			if (row < 0 || row >= n || col < 0 || col >= m)
				continue;
			if (!vis[row][col] && arr[row][col] == 1) {
				q.push({ row, col });
				vis[row][col] = true;
				if (step[row][col] == 0)
					step[row][col] = step[cur.first][cur.second] + 1;
				else
					step[row][col] = min(step[row][col], step[cur.first][cur.second] + 1);
			}
		}
	}
	cout << step[n - 1][m - 1];
	

	return 0;
}
