#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool vis[1002][1002];
int dis[1002][1002];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> n >> m;
	int** arr = new int* [m];
	for (int i = 0; i < m; i++) {
		arr[i] = new int[n];
	}

	int checkall = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				checkall = 0;
		}
	}
	if (checkall == 1) {
		cout << 0;
		return 0;
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				q.push({ i, j });
				vis[i][j] = true;
			}
		}
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int row = cur.first + dy[k];
			int col = cur.second + dx[k];
			if (row < 0 || row >= m || col < 0 || col >= n)
				continue;
			if (!vis[row][col] && arr[row][col] != -1) {
				q.push({ row, col });
				vis[row][col] = true;
				arr[row][col] = 1;
				if (dis[row][col] == 0)
					dis[row][col] = dis[cur.first][cur.second] + 1;
				else
					dis[row][col] = min(dis[row][col], dis[cur.first][cur.second] + 1);
			}
		}
	}
	
	int day = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (day < dis[i][j])
				day = dis[i][j];
		}
	}
	cout << day;

	return 0;
}
