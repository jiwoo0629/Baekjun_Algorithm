#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int i, j, n, k_count = 0, answer = 1000001;
pair<int, int> start;
char board[52][52];
int height[52][52];
bool vis[52][52];
vector<int> h_list; //높이들의 리스트
int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[8] = {0, -1, 0, 1, -1, 1, 1, -1};

int check(int x, int y) {
    if(height[x][y] < h_list[i] || height[x][y] > h_list[j] || vis[x][y]) return 0;
    vis[x][y] = true;
    int house_count = board[x][y] == 'K';
    for(int dir = 0; dir < 8; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        house_count += check(nx, ny);
    }
    return house_count;
}

int main(void) {
    cin >> n;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'P') start = {i, j};
            if(board[i][j] == 'K') k_count++;
        }
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            cin >> height[i][j];
            h_list.push_back(height[i][j]);
        }
    }
    sort(h_list.begin(), h_list.end());
    i=j=0;
    while(i < h_list.size() && j < h_list.size()) {
        for(int idx = 0; idx < 52; idx++) fill(vis[idx], vis[idx] + 52, false);
        if(check(start.first, start.second) == k_count) {
            answer = min(answer, h_list[j] - h_list[i]);
            i++;
        } 
        else j++;
    }
    cout << answer;

    return 0;
}
