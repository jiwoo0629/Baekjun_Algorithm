#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int board[21][21];
int step[21][21];
bool vis[21][21];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ans = 0;

//아기 상어 처음 크기는 2
//크기가 큰 물고기 : 지나가기 x 먹기 x
//크기가 같은 물고기 : 지나가기 o 먹기 x
//크기가 작은 물고기 : 지나가기 o 먹기 o
//먹을 수 있는 물고기가 1마리면 그 물고기를 먹으러 감
//먹을 수 있는 물고기가 1마리보다 많으면, 가장 가까운 물고기를 먹으러 감 (왼쪽 위) -> for문 사용
//상어 크기와 같은 수의 물고기를 먹으면 상어 크기 1 증가
//왔던 길 다시 돌아갈 수 있어야 함

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
    int a1, a2, a3, b1, b2, b3;
    tie(a1, a2, a3) = a;
    tie(b1, b2, b3) = b;
    if(a3 == b3) {
        if(a1 == b1) return a2 < b2;
        else return a1 < b1;
    }
    else return a3 < b3;
}

int main(void) {
    int n;
    cin >> n;
    pair<int, int> shark;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 9) { 
                shark = {i, j};
                board[i][j] = 0;
            }
        }
    }
    queue<tuple<int, int, int, int>> q; //상어 x좌표, y좌표, 현재 크기, 먹은 물고기 수
    q.push({shark.first, shark.second, 2, 0});
    while(!q.empty()) {
        int x, y, size, eat;
        tie(x, y, size, eat) = q.front();
        q.pop();
        //각 물고기까지의 거리 구하기
        for(int i=0; i<n; i++) {
            fill(step[i], step[i]+n, -1);
            fill(vis[i], vis[i]+n, false);
        }
        queue<pair<int, int>> nq;
        nq.push({x, y});
        step[x][y] = 0;
        vis[x][y] = true;
        vector<tuple<int, int, int>> v; //먹을 수 있는 물고기의 위치, 거리
        while(!nq.empty()) {
            pair<int, int> cur = nq.front();
            nq.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; //범위 벗어날 경우
                if(vis[nx][ny] || board[nx][ny] > size) continue; //해당 물고기가 상어보다 클 경우
                if(step[nx][ny] == -1) step[nx][ny] = step[cur.first][cur.second] + 1;
                else step[nx][ny] = min(step[nx][ny], step[cur.first][cur.second] + 1);
                nq.push({nx, ny});
                vis[nx][ny] = true;
                if(board[nx][ny] >= 1 && board[nx][ny] < size) //먹을 수 있는 물고기가 있는 경우
                    v.push_back({nx, ny, step[nx][ny]});
            }
        }
        if(v.size() == 0)  //갈 수 있는 칸이 없을 때의 예외처리
            break;
        stable_sort(v.begin(), v.end(), cmp); //거리 순으로 sort, 같은 경우 왼쪽 위 좌표 return
        int tx, ty, len; 
        tie(tx, ty, len) = v[0];
        ans += len;
        eat++;
        if(eat == size) {
            size++;
            eat = 0;
        }
        q.push({tx, ty, size, eat});
        board[tx][ty] = 0;
    }
    cout << ans;

    return 0;
}
