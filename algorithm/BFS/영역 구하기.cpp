#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int board[101][101];
bool vis[101][101];
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> n >> m >> k;
    while(k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i=n-y2; i<n-y1; i++) 
            for(int j=x1; j<x2; j++) board[i][j] = -1;
    }
       
    queue<pair<int, int>> q;
    vector<int> v;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!vis[i][j] && board[i][j] != -1) {
                int size = 1;
                vis[i][j] = true;
                q.push({i, j});
                while(!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for(int i=0; i<4; i++) {
                        int nx = cur.first + dx[i];
                        int ny = cur.second + dy[i];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny] || board[nx][ny] == -1) continue;
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                        size++;
                    }
                }
                v.push_back(size);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for(int i=0; i<v.size(); i++) cout << v[i] << " ";

    return 0;
}
