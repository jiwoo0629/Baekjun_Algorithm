#include <bits/stdc++.h>
using namespace std;

int m, n, h;
int board[102][102][102];
int dx[6] = { -1, 0, 0, 1, 0, 0 };
int dy[6] = { 0, -1, 0, 0, 1, 0 };
int dz[6] = { 0, 0, -1, 0, 0, 1 };
bool vis[102][102][102];
int dis[102][102][102];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;
    int checkall = 1;
    for(int k=0; k<h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[k][i][j];
                if (board[k][i][j] == 0)
                    checkall = 0;
            }      
        }
    }
    if (checkall == 1) {
        cout << 0;
        return 0;
    }

    queue<pair<int, pair<int, int>>> q;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[k][i][j] == 1) {
                    q.push({ k, {i,j} });
                    vis[k][i][j] = true;
                }
            }
        }
    }

    while (!q.empty()) {
        pair<int, pair<int, int>> cur = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = cur.second.first + dx[i];
            int ny = cur.second.second + dy[i];
            int nz = cur.first + dz[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
                continue;
            if (!vis[nz][nx][ny]) {
                if (board[nz][nx][ny] == -1) 
                    continue;
                else {
                    q.push({ nz, {nx, ny} });
                    vis[nz][nx][ny] = true;
                    if (dis[nz][nx][ny] == 0)
                        dis[nz][nx][ny] = dis[cur.first][cur.second.first][cur.second.second] + 1;
                    else
                        dis[nz][nx][ny] = min(dis[cur.first][cur.second.first][cur.second.second] + 1, dis[nz][nx][ny]);
                }
            }
        }
    }

    int day = 0;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[k][i][j] && board[k][i][j] != -1) {
                    cout << -1;
                    return 0;
                }
                day = max(day, dis[k][i][j]);
            }
        }
    }
    cout << day;

    return 0;
}
