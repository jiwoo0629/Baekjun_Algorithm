#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m, k;
int board[1002][1002];
int step[11][1002][1002];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<m; j++) board[i][j] = s[j] - '0';
    }
    queue< pair<int, pair<int, int>> > q;
    q.push({0, {0, 0}});
    step[0][0][0] = 1;
    while(!q.empty()) {
        pair<int, pair<int, int>> cur = q.front();
        q.pop();
        int crash = cur.first;
        int y = cur.second.first;
        int x = cur.second.second;
        if(y == n-1 && x == m-1) {
            cout << step[crash][y][x];
            return 0;
        }
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            int nz = crash;
            if(board[ny][nx] == 1) nz++;
            if(nz > k || step[nz][ny][nx] > 0) continue;
            step[nz][ny][nx] = step[crash][y][x] + 1;
            q.push({nz, {ny, nx}});
        }
    }
    cout << -1;

    return 0;
}
