#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

int r, c, x, y, type;
char board[51][51]; //'.' : 빈 곳, '*' : 물, 'X' : 돌(이동불가), 'D' : 비버의 굴(목표), 'S' : 고슴도치(시작))
int ans[51][51]; 
bool vis[51][51]; 
pair<int, int> d; //고슴도치의 굴 (목적지) 
queue<pair<int, int>> q_s, q_w; //고슴도치 큐, 물 큐 
vector<pair<int, int>> v; //임시 벡터
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for(int i=0; i<r; i++) {
        fill(ans[i], ans[i]+c, -1);
        for(int j=0; j<c; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'S') {
                q_s.push({i, j});
                ans[i][j] = 0;
            }
            else if(board[i][j] == 'D') d = {i, j};
            else if(board[i][j] == '*') {
                q_w.push({i, j}); //물이 우선순위라 먼저 넣음
                vis[i][j] = true;
            }
        }
    }
   
    while(!q_s.empty()) {
        v.clear();
        while(!q_w.empty()) { //물에 대해서 먼저 확인
            v.push_back(q_w.front());
            q_w.pop();
        }
        for(int i=0; i<v.size(); i++) {
            int x = v[i].first, y = v[i].second;
            for(int dir=0; dir<4; dir++) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(vis[nx][ny] || board[nx][ny] == 'X' || board[nx][ny] == 'D') continue;
                board[nx][ny] = '*';
                vis[nx][ny] = true;
                q_w.push({nx, ny}); 
            }
        }
        v.clear();
        while(!q_s.empty()) {
            v.push_back(q_s.front());
            q_s.pop();
        }
        for(int i=0; i<v.size(); i++) {
            int x = v[i].first, y = v[i].second;
            vis[x][y] = true;
            for(int dir=0; dir<4; dir++) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(vis[nx][ny] || board[nx][ny] == 'X' || board[nx][ny] == '*') continue;
                ans[nx][ny] = ans[x][y] + 1;
                vis[nx][ny] = true;
                q_s.push({nx, ny}); 
            }
        }
    }
    if(ans[d.first][d.second] == -1) cout << "KAKTUS";
    else cout << ans[d.first][d.second];

    return 0;
}
