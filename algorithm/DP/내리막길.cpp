#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int m, n;
int board[505][505], len[505][505];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int func(int x, int y){
  if(len[x][y] != -1) return len[x][y];
  if(x == m - 1 && y == n - 1) return 1;
  int &ret = len[x][y];
  ret = 0;
  for(int dir = 0; dir < 4; ++dir){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
    if(board[x][y] > board[nx][ny]) ret += func(nx, ny);
  }
  return ret;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> m >> n;
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
        cin >> board[i][j];
        len[i][j] = -1;
    }
  cout << func(0, 0);  
}

/* dfs를 적용한 버전 (시간초과) 

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int m, n;
int board[501][501];
int tempBoard[][];
int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0, -1, 0, 1};
int map [][]
bool visit [][]
int count [][] + 1 +1
int dfs(int x, int y) {

}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for(int i=0; i<m; i++) 
        for(int j=0; j<n; j++) cin >> board[i][j];

    stack<pair<int, int>> s;
    s.push({0, 0});
    int count = 0;
    while(!s.empty()) {
        pair<int, int> cur = s.top();
        s.pop();
        if(cur.first == m-1 && cur.second == n-1) {
            count++;
            continue;
        }
        int ret = len[x][y];
        for(int k=0; k<4; k++) {
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(board[cur.first][cur.second] <= board[nx][ny]) continue;
           ret += func(nx, ny);
           //s.push({nx, ny});
        }
        return ret;
    }    
    cout << func(0, 0);

    return 0;
}
*/
