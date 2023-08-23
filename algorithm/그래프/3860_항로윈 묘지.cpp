#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

//묘지의 입구로 들어가서 출구를 찾아야 함 (0, 0) -> (w-1, h-1)
//귀신 구멍 => 특정 시간이 지난 후(양수, 0, 음수) 다른 구멍으로 나옴

#define MAX 1000000001
int w, h, g, x, y; //너비(~30), 높이(~30), 묘비 수, 묘비 좌표
int e, x_1, y_1, x_2, y_2, t; //귀신구멍 수, 구멍 좌표, 이동 좌표, 시간(-10000 ~ 10000)
int nx, ny, nt;
long long board[31][31], bmf[31][31], tmp[31][31]; //묘지
map<pair<int, int>, tuple<int, int, int>> m; //{x1, y1} 좌표의 귀신구멍을 타면 t초 후에 {x2, y2} 좌표로 이동
vector<tuple<int, int, int>> v[31][31]; // 각 좌표별 이동 가능한 좌표 + 시간 저장
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		cin >> g;
		m.clear();
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				v[i][j].clear();
				board[i][j] = 0;
				bmf[i][j] = MAX;
			}
		}
		while (g--) {
			cin >> x >> y;
			board[x][y] = -1; //묘비 : -1
		}
		cin >> e;
		while (e--) {
			cin >> x_1 >> y_1 >> x_2 >> y_2 >> t;
			m[{x_1, y_1}] = { x_2, y_2, t };
			board[x_1][y_1] = -2; //귀신구멍 : -2
		}
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (board[i][j] == -2) { //귀신구멍에 들어간 경우, 무조건 구멍을 타게 됨
					tie(nx, ny, nt) = m[{i, j}];
					v[i][j].push_back({ nx, ny, nt });
					continue;
				}
				for (int dir = 0; dir < 4; dir++) {
					nx = i + dx[dir], ny = j + dy[dir];
					if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
					if (board[nx][ny] == -1) continue; //묘비로는 갈 수 없음
					v[i][j].push_back({ nx, ny, 1 });
				}
			}
		}
		bmf[0][0] = 0;
		for (int k = 1; k <= w * h - g; k++) {
			for (int i = 0; i < w; i++) {
				for (int j = 0; j < h; j++) {
					if (i == w - 1 && j == h - 1) continue;
					if (bmf[i][j] == MAX) continue;
					for (auto node : v[i][j]) {
						tie(nx, ny, nt) = node;
						bmf[nx][ny] = min(bmf[nx][ny], bmf[i][j] + nt);
					}
				}
			}
			if (k == w * h - g - 1) {
				for (int i = 0; i < w; i++)
					for (int j = 0; j < h; j++) tmp[i][j] = bmf[i][j];
			}
		}
		bool _cycle = false;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (tmp[i][j] != bmf[i][j])
					_cycle = true;
			}
		}
		//빠져나올 수 없으면 "Impossible", 계속 과거로 돌아가면 "Never", 가능하면 시간 출력
		if (_cycle) cout << "Never\n";
		else {
			if (tmp[w - 1][h - 1] == MAX) cout << "Impossible\n";
			else cout << tmp[w - 1][h - 1] << "\n";
		}
	}

	return 0;
}
