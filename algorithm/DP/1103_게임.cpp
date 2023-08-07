#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
string board[51];
int step[51][51];
int cnt[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool vis[51][51];

int dfs(int x, int y) {
	if(x < 0 || x >= n || y < 0 || y >= m || cnt[x][y] < 0) return 0;
    if(vis[x][y]) return -1;
    if(step[x][y]) return step[x][y];
    vis[x][y] = true;
    for(int dir = 0; dir < 4; dir++) {
        int a = dfs(x + dx[dir] * cnt[x][y], y + dy[dir] * cnt[x][y]);
        if(a < 0) return -1;
        step[x][y] = max(step[x][y], a);
    }
    vis[x][y] = false;
    return ++step[x][y];
}

int main(void) {
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> board[i];
		for(int j=0; j<m; j++) 
			cnt[i][j] = board[i][j] == 'H' ? -1 : (board[i][j] - '0');	
	}
	int result = dfs(0, 0);
	if(result > 0) cout << result;
	else cout << -1;
	return 0;
}
