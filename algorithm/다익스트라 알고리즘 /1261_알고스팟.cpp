#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>
using namespace std; 

#define MAX 10001
int n, m, dp[101][101];
bool vis[101][101];
string board[101];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for(int i=0; i<n; i++) {
        cin >> board[i];
        fill(dp[i], dp[i]+m, MAX);
    }
    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, 0, 0});
    dp[0][0] = 0;
    while(!pq.empty()) {
        int dist, x, y;
        tie(dist, x, y) = pq.top();
        dist = -dist;
        pq.pop();
        if(vis[x][y]) continue;
        vis[x][y] = true;
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dp[nx][ny] > dist + (board[nx][ny] - '0')) {
                dp[nx][ny] = dist + (board[nx][ny] - '0');
                pq.push({-dp[nx][ny], nx, ny});
            }
        }
    }
    cout << dp[n-1][m-1];

    return 0;
}
