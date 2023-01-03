#include <bits/stdc++.h>
using namespace std;

int R, C;
char maze[1002][1002];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int tim[1002][1002];
int tim_F[1002][1002];


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> R >> C;
	queue<pair<int, int>> q;
	queue <pair<int, int>> q_F;
	for (int i = 0; i < R; i++) {
		fill(tim[i], tim[i] + C, -1);
		fill(tim_F[i], tim_F[i] + C, -1);
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			maze[i][j] = str[j];
			if (str[j] == 'J') {
				q.push({ i, j });
				tim[i][j] = 0;
			}
			if (str[j] == 'F') {
				q_F.push({ i, j });
				tim_F[i][j] = 0;
			}
		}
	}

	while (!q_F.empty()) {
		pair<int, int> cur_F = q_F.front();
		q_F.pop();
		for (int i = 0; i < 4; i++) {
			int x_F = cur_F.first + dx[i];
			int y_F = cur_F.second + dy[i];
			if (x_F < 0 || x_F >= R || y_F < 0 || y_F >= C)
				continue;
			if (tim_F[x_F][y_F] >= 0 || maze[x_F][y_F] == '#')
				continue;
			q_F.push({ x_F, y_F });
			tim_F[x_F][y_F] = tim_F[cur_F.first][cur_F.second] + 1;	
		}
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = cur.first + dx[i];
			int y = cur.second + dy[i];
			if (x < 0 || x >= R || y < 0 || y >= C) {
				cout << tim[cur.first][cur.second] + 1;
				return 0;
			}
			if (maze[x][y] == '#' || tim[x][y] >= 0)
				continue;
			if (tim_F[x][y] != -1 && tim_F[x][y] <= tim[cur.first][cur.second] + 1)
				continue;
			q.push({ x, y });
			tim[x][y] = tim[cur.first][cur.second] + 1;
		}	
	}
	cout << "IMPOSSIBLE";

	return 0;
}
