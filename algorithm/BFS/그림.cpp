#include <bits/stdc++.h>
using namespace std;

bool vis[502][502];
int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> n >> m;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	queue<pair<int, int>> q;
	int pic = 0, max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] && arr[i][j] == 1) {
				vis[i][j] = true;
				q.push({ i, j });
				int size = 1;
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
							size++;
						}
					}
				}
				pic++;
				if (max < size)
					max = size;
			}
		}
	}
	cout << pic << "\n" << max;

	return 0;
}
