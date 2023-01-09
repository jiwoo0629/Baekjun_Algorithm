#include <bits/stdc++.h>
using namespace std;

int n, k;
int board[100002];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(board, board + 100002, -1);

    cin >> n >> k;
    queue<int> q;
    q.push(n);
    board[n] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == 0) {
            if (board[cur + 1] == -1) {
                board[cur + 1] = board[cur] + 1;
                q.push(cur + 1);
            }
        }
        else if (cur == 100000) {
            if (board[cur - 1] == -1) {
                board[cur - 1] = board[cur] + 1;
                q.push(cur - 1);
            }
        }
        else if (cur * 2 > 100000) {
            if (board[cur - 1] == -1) {
                board[cur - 1] = board[cur] + 1;
                q.push(cur - 1);
            }
            if (board[cur + 1] == -1) {
                board[cur + 1] = board[cur] + 1;
                q.push(cur + 1);
            }
        }
        else {
            //칸수가 2배씩 뛸 경우 시간이 0초 들기 때문에 최소 시간을 구할 때, 이 경우를 우선으로 고려해야 한다.
            if (board[cur * 2] == -1) { 
                board[cur * 2] = board[cur];
                q.push(cur * 2);
            }
            if (board[cur - 1] == -1) {
                board[cur - 1] = board[cur] + 1;
                q.push(cur - 1);
            }
            if (board[cur + 1] == -1) {
                board[cur + 1] = board[cur] + 1;
                q.push(cur + 1);
            }
        }
        
        if (board[k] != -1) {
            cout << board[k];
            return 0;
        }
    }

    return 0;
}
