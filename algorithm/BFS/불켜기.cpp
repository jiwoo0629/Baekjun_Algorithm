#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int room[101][101]; // 0 : off, 1 : on
bool vis[101][101];
vector<pair<int, int>> onoff[101][101]; //해당 방에서 불을 켜고 끌 수 있는 방들의 좌표를 담은 vector
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> q; 
    cin >> n >> m;
    while(m--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        onoff[x][y].push_back({a, b});
    }
    room[1][1] = 1;
    vis[1][1] = true;
    q.push({1, 1});
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
//현 위치에서 켤 수 있는 불 다 켜기
//이동할 수 있는 범위 안에서 onlist에 있는 애 중에 이동안한 곳 있으면 이동
        for(int i=0; i<onoff[cur.first][cur.second].size(); i++) {
            int x = onoff[cur.first][cur.second][i].first;
            int y = onoff[cur.first][cur.second][i].second;
            if(vis[x][y]) continue;
            bool canmove = false; //이동할 수 있는 곳인지 확인
            for(int k=0; k<4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
                if(vis[nx][ny]) {
                    canmove = true;
                    break;
                }
            }
            if(canmove) {
                vis[x][y] = true;
                q.push({x, y});
            }
            room[x][y] = 1; //불 켜기
        }
        for(int k=0; k<4; k++) { //이동할 수 있으면 이동
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if(vis[nx][ny] || room[nx][ny] == 0) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
        
    }
    int on = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            if(room[i][j] == 1) on++;
    }
    cout << on;

    return 0;
}
