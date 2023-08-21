#include <iostream>
using namespace std;

int i, j, h, w, n; // (1, 1) : 시작점, (h, w) : 끝점, n : n번째 산책 경로 (좌표)
int board[1005][1005]; //0 : 아래로 이동, 1 : 오른쪽으로 이동
int dp[1005][1005]; //이 좌표를 밟은 횟수

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //매번마다 확인하려면, 한 사이클 당 20회 연산 이내에 완료해야 함
    //다른 방법?? => DP
    //n번째 지도를 얻으려면, n-1번 산책 후의 값을 알 수 있어야 한다.
    cin >> h >> w >> n;
    dp[0][0] = n-1;
    for(i=0; i<h; i++) {
        for(j=0; j<w; j++) {
            cin >> board[i][j];
            //내 기준 아래 점 => 내 값의 절반 + (아래를 가리킬 경우, 1 더해줌)
            dp[i+1][j] += ( dp[i][j] / 2 + ((dp[i][j] & 1) * (board[i][j] == 0)) );
            //내 기준 오른쪽 점 => 내 값의 절반 + (오른쪽을 가리킬 경우, 1 더해줌)
            dp[i][j+1] += ( dp[i][j] / 2 + ((dp[i][j] & 1) * (board[i][j] == 1)) );
            board[i][j] ^= (dp[i][j] & 1);
        }
    }
    i=0, j=0;
    while(i < h && j < w) { 
        if(board[i][j] == 0) i++; //아래로 이동
        else j++; //오른쪽으로 이동
    }
    cout << i+1 << " " << j+1;
    return 0;
}
