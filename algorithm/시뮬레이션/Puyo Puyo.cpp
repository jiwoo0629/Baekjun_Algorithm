#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

string field[12]; 
int dx[4] = { -1, 0 ,1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int puyo = 0; //연쇄 횟수

int main(void) {
    for(int i=0; i<12; i++) cin >> field[i];
    bool pop = true; //연쇄가 있었는지 없었는지 확인
    while(pop) {
        pop = false; 
        for(int i=0; i<12; i++) {
            for(int j=0; j<6; j++) {
                if(field[i][j] =='.') continue;
                vector<pair<int, int>> v; //pop할 칸들의 좌표를 저장할 벡터
                queue<pair<int, int>> q; //bfs를 위한 큐
                bool vis[12][6] = {false, };
                v.push_back({i, j});
                q.push({i, j});
                vis[i][j] = true;
                int size = 1;
                while(!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for(int dir=0; dir<4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue; //범위를 벗어날 경우
                        if(vis[nx][ny]) continue; //이미 방문한 칸일 경우
                        if(field[cur.first][cur.second] != field[nx][ny]) continue; //다른 색일 경우
                        v.push_back({nx, ny});
                        q.push({nx, ny});
                        vis[nx][ny] = true;
                        size++;
                    }
                }
                if(size >= 4) { //4개 이상 상하좌우로 연결되어 있는 경우, 연쇄
                    pop = true; //연쇄가 일어났음을 알림
                    while(!v.empty()) {
                        pair<int, int> cur = v.back();
                        v.pop_back();
                        field[cur.first][cur.second] = '.';
                    }
                }
            }
        }
        //연쇄의 효과로 puyo를 아래로 떨어뜨림
        for(int k=0; k<6; k++) {
            vector<char> v2; //각 줄마다 남아있는 puyo만 확인
            for(int l=11; l>=0; l--) 
                if(field[l][k] != '.') v2.push_back(field[l][k]);
            int num = 12 - v2.size();
            for(int l=0; l<num; l++) v2.push_back('.');
            for(int l=0; l<v2.size(); l++) field[11-l][k] = v2[l];
        }
        if(pop) puyo++; //연쇄가 일어났을 경우, puyo + 1
    }
    cout << puyo;

    return 0;
}
