#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int board[8][8];
int n_board[8][8];
bool vis[8][8];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ans = 0;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v0; //빈칸 위치
    vector<pair<int, int>> v2; //바이러스 위치
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0) v0.push_back({i, j});
            else if(board[i][j] == 2) v2.push_back({i, j});
        }
    }
    vector<int> v;
    for(int i=0; i<3; i++) v.push_back(1);
    for(int i=3; i<v0.size(); i++) v.push_back(0);
    sort(v.begin(), v.end());
    do{
        for(int i=0; i<n; i++) {
            fill(vis[i], vis[i]+m, false);
            for(int j=0; j<m; j++) n_board[i][j] = board[i][j];
        }
        queue<pair<int, int>> q;
        for(int i=0; i<v.size(); i++) 
            if(v[i] == 1) n_board[v0[i].first][v0[i].second] = 1;
        for(int i=0; i<v2.size(); i++) {
            q.push(v2[i]);
            vis[v2[i].first][v2[i].second] = true;
        }
        while(!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(vis[nx][ny] || n_board[nx][ny] == 1) continue;
                q.push({nx, ny});
                n_board[nx][ny] = 2;
                vis[nx][ny] = true;
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++)
                if(n_board[i][j] == 0) cnt++;
        }
        ans = max(ans, cnt);
    } while(next_permutation(v.begin(), v.end()));
    cout << ans;

    return 0;
}
