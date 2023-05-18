#include <iostream>
#include <vector>
using namespace std;

int n, m;
int board[8][8];
int newboard[8][8];
vector<pair<int, int>> cctv; //cctv가 있는 위치들
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ans = 0; //사각지대의 개수

bool canmove(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    else return true;
}

void fillboard(int x, int y, int dir) {
    dir %= 4;
    while(1) {
        x += dx[dir];
        y += dy[dir];
        if(!canmove(x, y) || board[x][y] == 6) return;
        if(newboard[x][y] != 0) continue;
        newboard[x][y] = -1;
    }
}

int main(void) {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] >= 1 && board[i][j] <= 5) cctv.push_back({i, j});
            if(board[i][j] == 0) ans++;
        }
    }

    for(int k=0; k<1<<(2*cctv.size()); k++) {
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) newboard[i][j] = board[i][j];
        int tmp = k;
        for(int i=0; i<cctv.size(); i++) {
            int dir = tmp % 4;
            tmp /= 4;
            int x = cctv[i].first;
            int y = cctv[i].second;
            if(board[x][y] == 1) fillboard(x, y, dir);
            else if(board[x][y] == 2) {
                fillboard(x, y, dir);
                fillboard(x, y, dir+2);
            }
            else if(board[x][y] == 3) {
                fillboard(x, y, dir);
                fillboard(x, y, dir+1);
            }
            else if(board[x][y] == 4) {
                fillboard(x, y, dir);
                fillboard(x, y, dir+1);
                fillboard(x, y, dir+2);
            }
            else {
                fillboard(x, y, dir);
                fillboard(x, y, dir+1);
                fillboard(x, y, dir+2);
                fillboard(x, y, dir+3);
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) 
                if(newboard[i][j] == 0) cnt++;
        }
        ans = min(ans, cnt);
    }
    cout << ans;

    return 0;
}
