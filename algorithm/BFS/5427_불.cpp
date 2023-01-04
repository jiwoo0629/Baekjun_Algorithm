#include <bits/stdc++.h>
using namespace std;

string build[1002];
int w, h;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int dis1[1002][1002]; //불
int dis2[1002][1002]; //상근

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t-- > 0) {
        queue<pair<int, int>> q1; //불
        queue<pair<int, int>> q2; //상근
        bool find = false;
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            fill(dis1[i], dis1[i] + w, 0);
            fill(dis2[i], dis2[i] + w, 0);
            cin >> build[i];
            for (int j = 0; j < w; j++) {
                if (build[i][j] == '*') {
                    q1.push({ i, j });
                    dis1[i][j] = 1;
                }
                else if (build[i][j] == '@') {
                    q2.push({ i, j });
                    dis2[i][j] = 1;
                }
            }
        }
        while (!q1.empty()) {
            pair<int, int> cur = q1.front();
            q1.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                    continue;
                if (dis1[nx][ny] || build[nx][ny] == '#')
                    continue;
                q1.push({ nx, ny });
                dis1[nx][ny] = dis1[cur.first][cur.second] + 1;
            }
        }
        while (!q2.empty() && !find) {
            pair<int, int> cur = q2.front();
            q2.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dy[i];
                int ny = cur.second + dx[i];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) { //탈출할 경우
                    cout << dis2[cur.first][cur.second] << "\n";
                    find = true;
                    break;
                }
                if (dis2[nx][ny] || build[nx][ny] == '#') //빈 공간이 아닐 경우
                    continue;
                if (dis1[nx][ny] != 0 && dis1[nx][ny] <= dis2[cur.first][cur.second] + 1)
                    continue;
                q2.push({ nx, ny });
                dis2[nx][ny] = dis2[cur.first][cur.second] + 1;
            }
        }
        if(!find)
            cout << "IMPOSSIBLE\n";
    }

    return 0;
}
