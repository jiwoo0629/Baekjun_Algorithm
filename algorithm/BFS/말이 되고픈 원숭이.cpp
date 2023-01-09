#include <bits/stdc++.h>
using namespace std;

int k, w, h;
int board[202][202];
int dis[32][202][202];

int dx1[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy1[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dx2[4] = { -1, 0, 1, 0 };
int dy2[4] = { 0, -1, 0, 1 };

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cin >> board[i][j];
    }

    queue<tuple<int, int, int>> q;
    q.push({ 0, 0, 0 });
    dis[0][0][0] = 1;

    while (!q.empty()) {
        int l, x, y;
        tie(l, x, y) = q.front();
        q.pop();
        if (l < k) {
            for (int i = 0; i < 8; i++) {
                int nx = x + dx1[i];
                int ny = y + dy1[i];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (board[nx][ny] == 1) continue;
                if (dis[l + 1][nx][ny] > 0) continue;
                dis[l + 1][nx][ny] = dis[l][x][y] + 1;
                q.push({ l+1, nx, ny });
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx2[i];
            int ny = y + dy2[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (board[nx][ny] == 1) continue;
            if (dis[l][nx][ny] > 0) continue;
            dis[l][nx][ny] = dis[l][x][y] + 1;
            q.push({ l, nx, ny });
        }
    }
    
    int answer = 202 * 202;
    for (int i = 0; i <= k; i++)
        if (dis[i][h - 1][w - 1] > 0) answer = min(answer, dis[i][h - 1][w - 1]);
    if (answer != 202 * 202) cout << answer - 1;
    else cout << -1;

    return 0;
}
