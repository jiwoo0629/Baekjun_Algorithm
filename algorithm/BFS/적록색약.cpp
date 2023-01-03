#include <bits/stdc++.h>
using namespace std;

int n;
string board[102];
bool vis[102][102];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> board[i];
    
    for (int i = 0; i < n; i++)
        fill(vis[i], vis[i] + n, false);

    int able = 0, disable = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                q.push({ i,j });
                vis[i][j] = true;
                able++;
            }
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if (!vis[nx][ny]) {
                        if (board[cur.first][cur.second] != board[nx][ny])
                            continue;
                        else {
                            q.push({ nx, ny });
                            vis[nx][ny] = true;
                        }
                    } 
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        fill(vis[i], vis[i] + n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                q.push({ i,j });
                vis[i][j] = true;
                disable++;
            }
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if ((!vis[nx][ny]) && ((board[nx][ny] == 'G' && board[cur.first][cur.second] == 'R') || (board[nx][ny] == 'R' && board[cur.first][cur.second] == 'G') || (board[nx][ny] == board[cur.first][cur.second]))) {
                        q.push({ nx, ny });
                        vis[nx][ny] = true;
                    }
                }
            }
        }
    }
    cout << able << ' ' << disable;
    
    return 0;
}
