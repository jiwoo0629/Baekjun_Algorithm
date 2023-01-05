#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[1002];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int dis[2][1002][1002];
//dis[0][y][x] : 벽을 하나도 부수지 않고 (y,x)까지 가는 비용
//dis[1][y][x] : 벽을 하나 부수고 (y,x)까지 가는 비용

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        cin >> board[i];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            dis[0][i][j] = dis[1][i][j] = -1;
    }
    dis[0][0][0] = dis[1][0][0] = 1;

    queue<pair<int, pair<int, int>>> q;
    q.push({ 0, { 0,0 } });
    while (!q.empty()) {
        pair<int, pair<int, int>> cur = q.front();
        int crash = cur.first;
        int y = cur.second.first;
        int x = cur.second.second;
        if (y == n - 1 && x == m - 1) {
            cout << dis[crash][y][x];
            return 0;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (board[ny][nx] == '0' && dis[crash][ny][nx] == -1) {
                dis[crash][ny][nx] = dis[crash][y][x] + 1;
                q.push({ crash, {ny, nx} });
            }
            //벽을 부수는 경우
            if (!crash && board[ny][nx] == '1' && dis[1][ny][nx] == -1) {
                dis[1][ny][nx] = dis[crash][y][x] + 1;
                q.push({ 1, {ny, nx} });
            }
        }
    }
    cout << -1;
    
    return 0;
}
