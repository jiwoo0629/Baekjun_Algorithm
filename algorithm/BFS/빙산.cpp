#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[300][300];
int newboard[300][300];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
bool vis[300][300];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    int year = 0;
    while (1) {
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != 0) {
                    int cnt = 0;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;
                        else if (board[nx][ny] == 0)
                            cnt++;
                    }
                    newboard[i][j] = board[i][j] - cnt;
                    if (newboard[i][j] < 0)
                        newboard[i][j] = 0;
                }
                else
                    newboard[i][j] = board[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                board[i][j] = newboard[i][j];
        }

        int num = 0;
        for (int i = 0; i < n; i++)
            fill(vis[i], vis[i] + m, false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                queue<pair<int, int>> q;
                if (!vis[i][j] && board[i][j] != 0) {
                    q.push({ i, j });
                    vis[i][j] = true;
                }
                else
                    continue;
                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;
                        if (!vis[nx][ny] && board[nx][ny] != 0) {
                            q.push({ nx, ny });
                            vis[nx][ny] = true;
                        }
                    }
                }
                num++;
            }
        }
        if (num > 1) {
            cout << year + 1;
            return 0;
        }
        year++;
    }
    cout << 0;

    return 0;
}
