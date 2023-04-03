#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int board[101][101];
bool vis[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    for(int i=0; i<k; i++) {
        string s;
        cin >> s;
        for(int j=0; j<s.length(); j++) 
            board[i][j] = s[j] - '0';
    }
       
    queue<pair<int, int>> q;
    vector<int> v;
    for(int i=0; i<k; i++) {
        for(int j=0; j<k; j++) {
            if(!vis[i][j] && board[i][j] == 1) {
                int size = 1;
                vis[i][j] = true;
                q.push({i, j});
                while(!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for(int i=0; i<4; i++) {
                        int nx = cur.first + dx[i];
                        int ny = cur.second + dy[i];
                        if(nx < 0 || nx >= k || ny < 0 || ny >= k) continue;
                        if(vis[nx][ny] || board[nx][ny] == 0) continue;
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
    for(int i=0; i<v.size(); i++) cout << v[i] << "\n";

    return 0;
}
