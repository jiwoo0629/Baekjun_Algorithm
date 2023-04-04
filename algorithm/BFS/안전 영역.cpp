#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int area[101];
int board[101][101];
bool vis[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int max = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
            if(max < board[i][j]) max = board[i][j];
        }
    }
    for(int l=0; l<max; l++) {
        for(int i=0; i<n; i++) 
            fill(vis[i], vis[i]+n, false);
        int block = 0;
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j] && board[i][j] > l) {
                    vis[i][j] = true;
                    q.push({i, j});
                    while(!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();
                        for(int k=0; k<4; k++) {
                            int nx = cur.first + dx[k];
                            int ny = cur.second + dy[k];
                            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                            if(vis[nx][ny] || board[nx][ny] <= l) continue;
                            q.push({nx, ny});
                            vis[nx][ny] = true;
                        }
                    }
                    block++;
                }
            }
        }
        area[l] = block;      
    }
    cout << *max_element(area, area+100);


    return 0;
}
