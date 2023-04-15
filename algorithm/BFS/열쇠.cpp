#include <iostream>
#include <queue>

using namespace std;

int h, w;
char map[102][102];
bool vis[102][102];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int ans = 0;
        bool key[26] = {false, }; //해당 열쇠를 갖고 있는지 유무
        cin >> h >> w;
        for(int i=0; i<h+2; i++) {
            fill(vis[i], vis[i]+w+2, false);
            fill(map[i], map[i]+w+2, 0);
        } 
        for(int i=1; i<=h; i++) 
            for(int j=1; j<=w; j++) cin >> map[i][j];
        string str;
        cin >> str;
        for(int i=0; i<str.length(); i++) key[str[i] - 'a']  = true;
        
        queue<pair<int, int>> q;
        queue<pair<int, int>> door[26]; //알파벳 별 열어야 하는 문의 좌표
        q.push({0, 0});
        vis[0][0] = true;
        while(!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for(int k=0; k<4; k++) {
                int nx = cur.first + dx[k];
                int ny = cur.second + dy[k];
                if(nx < 0 || nx > h+1 || ny < 0 || ny > w+1) continue;
                if(vis[nx][ny] || map[nx][ny] == '*') continue;
                if(map[nx][ny] >= 'a' && map[nx][ny] <= 'z') { //열쇠
                    int l = map[nx][ny] - 'a';
                    key[l] = true;
                    while(!door[l].empty()) {
                        pair<int, int> ncur = door[l].front();
                        door[l].pop();
                        q.push({ncur.first, ncur.second});
                    }
                }
                else if(map[nx][ny] >= 'A' && map[nx][ny] <= 'Z') { //문
                    int l = map[nx][ny] + 32 - 'a';
                    if(!key[l]) { //열쇠가 없어서 아직 열 수 없는 경우
                        door[l].push({nx, ny});
                        continue;
                    }
                }
                else if(map[nx][ny] == '$')  //서류
                    ans++;
                q.push({nx, ny});
                vis[nx][ny] = true;
            }   
        }
        cout << ans << "\n";
    }

    return 0;
}
