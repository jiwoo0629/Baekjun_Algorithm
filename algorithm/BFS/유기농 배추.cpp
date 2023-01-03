#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t-- > 0) {
        int board[52][52];
        bool vis[52][52];
        int m, n, k;
        cin >> m >> n >> k;
        for (int i = 0; i < n; i++) {
            fill(board[i], board[i] + m, 0);
            fill(vis[i], vis[i] + m, false);
        }  
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }

        int bug = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                queue<pair<int, int>> q;
                if (!vis[i][j] && board[i][j] == 1) {
                    q.push({ i, j });
                    vis[i][j] = true;
                    bug++;
                }
                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int h = 0; h < 4; h++) {
                        int ny = cur.first + dx[h];
                        int nx = cur.second + dy[h];
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                            continue;
                        if (board[ny][nx] == 0)
                            continue;
                        if (!vis[ny][nx] && board[ny][nx] == 1) {
                            q.push({ ny, nx });
                            vis[ny][nx] = true;
                        }
                    }
                }
            }
        }
        cout << bug << "\n";
    }
    
    return 0;
}
