#include <iostream>
#include <queue>
using namespace std;

int r, c;
char lake[1505][1505];
bool vis[1505][1505]; //이번에 확장할 칸
bool lvis[1505][1505]; //이미 확장한 칸
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<pair<int, int>> qw, qw2; //호수 확장용, 임시저장용
queue<pair<int, int>> q, q2; //백조 탐색용, 임시저장용
//qw2, q2는 1칸씩만 확장하고 확인하기 위해, while문을 빠져나온 뒤에 작업을 몰아서 하기 위해 사용
pair<int, int> swan; //백조가 있는 칸

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> lake[i][j];
            if(lake[i][j] != 'X') qw.push({i, j}); //물로 되어 있는 칸 삽입
            if(lake[i][j] == 'L') swan = {i, j};        
        }
    }
    
    int day = 0;
    q.push({swan.first, swan.second});
    vis[swan.first][swan.second] = true;
    lake[swan.first][swan.second] = '.';

    while(1) {
        //아직 만날 수 없는 경우, 호수 확장 시작
        while(!qw.empty()) { //물로 되어 있는 모든 칸 확인
            pair<int, int> cur = qw.front();
            qw.pop();
            lvis[cur.first][cur.second] = true; //칸 확인
            for(int dir=0; dir<4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue; //범위를 벗어나면 통과
                if(lvis[nx][ny]) continue;
                if(lake[nx][ny] == 'X') qw2.push({nx, ny});
                lvis[nx][ny] = true;
            }
        }
        while(!qw2.empty()) {
            pair<int, int> cur = qw2.front();
            qw2.pop();
            lake[cur.first][cur.second] = '.';
            qw.push({cur.first, cur.second});
        }
        day++; //날짜 추가

        //두 백조가 만날 수 있는지 확인
        while(!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(vis[nx][ny]) continue;
                vis[nx][ny] = true;
                if(lake[nx][ny] == 'X') {
                    q2.push({nx, ny});
                    continue;
                }
                if(lake[nx][ny] == 'L') { //두 백조가 만날 경우, 걸린 날 출력 후 종료
                    cout << day;
                    return 0;
                }
                q.push({nx, ny});
            }
        }
        while(!q2.empty()) {
            pair<int, int> cur = q2.front();
            q2.pop();
            q.push({cur.first, cur.second});
        }
    }

    return 0;
}

/* 시간초과 - 최악의 경우 O(max(r,c) * r * c) = 약 1500^3 

#include <iostream>
#include <queue>
using namespace std;

int r, c;
char lake[1505][1505];
bool vis[1505][1505];
bool lvis[1505][1505];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> qw;
    pair<int, int> swan;
    cin >> r >> c;
    for(int i=0; i<r; i++) 
        for(int j=0; j<c; j++) {
            cin >> lake[i][j];
            if(lake[i][j] == '.') qw.push({i, j}); //물로 되어 있는 칸 삽입
            if(lake[i][j] == 'L') {
                swan = {i, j};
                qw.push({i, j});
            }
        }
    int day = 0;
    while(1) {
        for(int i=0; i<r; i++) fill(lvis[i], lvis[i] + c, false); 
        //두 백조가 만날 수 있는지 확인
        queue<pair<int, int>> q;
        q.push({swan.first, swan.second});
        lvis[swan.first][swan.second] = true;
        while(!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(lvis[nx][ny] || lake[nx][ny] == 'X') continue;
                if(lake[nx][ny] == 'L') { //두 백조가 만날 경우, 걸린 날 출력 후 종료
                    cout << day;
                    return 0;
                }
                q.push({nx, ny});
                lvis[nx][ny] = true;
            }
        }

        //아직 만날 수 없는 경우, 호수 확장 시작
        while(!qw.empty()) { //물로 되어 있는 모든 칸 확인
            pair<int, int> cur = qw.front();
            qw.pop();
            if(vis[cur.first][cur.second]) continue; //이미 확인한 칸이면 통과
            vis[cur.first][cur.second] = true; //칸 확인
            for(int dir=0; dir<4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue; //범위를 벗어나면 통과
                if(lake[nx][ny] == '.') continue; //옆 칸이 이미 물이면 통과
                if(lake[nx][ny] == 'X') lake[nx][ny] = '.';
            }
        }
        day++; //날짜 추가
        for(int i=0; i<r; i++) { //물로 되어 있는 칸 삽입
            for(int j=0; j<c; j++) 
                if(lake[i][j] == '.' && !vis[i][j]) qw.push({i, j});
        }
    }

    return 0;
}
*/
