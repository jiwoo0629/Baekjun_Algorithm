#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m, g, r;
char board[51][51];
char garden[51][51];
int ftime[51][51];
vector<pair<int, int>> canseed;
int seed = 0;
bool vis[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int maxseed = 0;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> g >> r;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] == '2') {
                seed++;
                canseed.push_back({i, j});
            }
        }
    }

    vector<int> v;
    for(int i=0; i<g; i++) v.push_back(1);
    for(int i=0; i<r; i++) v.push_back(2);
    for(int i=0; i<seed-g-r; i++) v.push_back(0);
    sort(v.begin(), v.end());

    do {
        for(int i=0; i<n; i++) {
            fill(ftime[i], ftime[i]+m, -1);
            fill(vis[i], vis[i]+m, false);
            for(int j=0; j<m; j++) garden[i][j] = board[i][j];
        }
        int cnt = 0;
        queue<tuple<char, int, int, int>> q; //색, 시간, x, y
        for(int k=0; k<seed; k++) {
            pair<int, int> cur = canseed[k];
            if(v[k] == 1) {
                garden[cur.first][cur.second] = 'g';
                q.push({'g', 0, cur.first, cur.second});
                ftime[cur.first][cur.second] = 0;
                vis[cur.first][cur.second] = true;
            }
            if(v[k] == 2) {
                garden[cur.first][cur.second] = 'r';
                q.push({'r', 0, cur.first, cur.second});
                ftime[cur.first][cur.second] = 0;
                vis[cur.first][cur.second] = true;
            }
        }
        while(!q.empty()) {
            int time, x, y;
            char color;
            tie(color, time, x, y) = q.front();
            q.pop();
            if(garden[x][y] == 'f') continue;
            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(garden[nx][ny] == '0' || garden[nx][ny] == 'f') continue; //이동할 수 없는 곳이거나 이미 꽃이 생긴 경우
                if(vis[nx][ny]) {
                    if(garden[nx][ny] == color) continue;
                    if(ftime[nx][ny] != time + 1) continue;
                    if((color == 'g' && garden[nx][ny] == 'r') || (color == 'r' && garden[nx][ny] == 'g')){
                        garden[nx][ny] = 'f';
                        continue;
                    }
                }
                vis[nx][ny] = true;
                garden[nx][ny] = color;
                ftime[nx][ny] = time + 1;
                q.push({color, time+1, nx, ny});
            }
        }
        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++) if(garden[i][j] == 'f') cnt++;
        maxseed = max(maxseed, cnt);
    } while(next_permutation(v.begin(), v.end()));
    
    cout << maxseed;

    return 0;
}
