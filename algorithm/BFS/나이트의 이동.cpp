#include <bits/stdc++.h>
using namespace std;

int l;
bool vis[302][302];
int dis[302][302];
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t-- > 0) {
        cin >> l;
        for (int i = 0; i < l; i++) {
            fill(vis[i], vis[i] + l, false);
            fill(dis[i], dis[i] + l, 0);
        }
        queue<pair<int, int>> q;
        int x1, y1, x2, y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        if (x1 == x2 && y1 == y2) {
            cout << 0 << "\n";
            continue;
        }
        q.push({ x1, y1 });
        vis[x1][y1] = true;
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            int find = 0;
            q.pop();
            for (int i = 0; i < 8; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx < 0 || nx >= l || ny < 0 || ny >= l)
                    continue;
                if (!vis[nx][ny]) {
                    q.push({ nx, ny });
                    vis[nx][ny] = true;
                    if (dis[nx][ny] == 0)
                        dis[nx][ny] = dis[cur.first][cur.second] + 1;
                    else
                        dis[nx][ny] = min(dis[nx][ny], dis[cur.first][cur.second] + 1);
                }
                if (nx == x2 && ny == y2) {
                    cout << dis[nx][ny] << "\n";
                    find = 1;
                    break;
                }
            }
            if (find == 1) 
                break;
        }
    }

    return 0;
}
