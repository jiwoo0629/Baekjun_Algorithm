#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m, k;
string board[1002];
int step[2][12][1002][1002]; //0 : 낮, 1 : 밤
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    queue<tuple<int, int, int, int>> q;
    for(int i=0; i<n; i++) cin >> board[i];
    step[0][0][0][0] = 1;
    q.push({0, 0, 0, 0});
    while(!q.empty()) {
        int day, crash, y, x; //day => 0 : 낮, 1 : 밤
        tie(day, crash, y, x) = q.front(); 
        q.pop();
        if(y == n-1 && x == m-1) {
            cout << step[day][crash][y][x];
            return 0;
        }
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(board[ny][nx] == '0') { //그냥 갈 수 있는 경우
                int nh = crash;
                int nd = 1-day; //낮->밤 / 밤->낮
                if(step[nd][nh][ny][nx] > 0) continue;
                step[nd][nh][ny][nx] = step[day][crash][y][x]+1;
                q.push({nd, nh, ny, nx});
            }
            else { //벽을 부수고 가야 하는 경우
                if(crash == k) continue; //부술 수 있는 횟수를 다 채운 경우
                if(day == 0) { //낮일 경우 부수고 갈 수 있음
                    int nh = crash + 1; //부순 횟수 1 추가
                    int nd = 1-day;
                    if(step[nd][nh][ny][nx] > 0) continue;
                    step[nd][nh][ny][nx] = step[day][crash][y][x]+1;
                    q.push({nd, nh, ny, nx});
                }
                else { //밤일 경우 그 자리에서 머물러있기
                    int nd = 1-day;
                    if(step[nd][crash][y][x] > 0) continue;
                    step[nd][crash][y][x] = step[day][crash][y][x] + 1;
                    q.push({nd, crash, y, x});
                }
            }
        }
    }
    cout << -1;
   
    return 0;
}
