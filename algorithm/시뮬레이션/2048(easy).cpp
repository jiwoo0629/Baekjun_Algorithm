#include <iostream>
#include <vector>
using namespace std;

int n;
int board[21][21];
int board2[21][21]; //매 시행에 대해 board 배열을 복사할 임시 배열
int ans = 0; //최댓값

void rotate() {  //board2를 시계 방향으로 90도 회전하는 함수 (네 방향에 대해 왼쪽으로 기울인 결과 )
    int tmp[21][21];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) tmp[i][j] = board2[i][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) board2[i][j] = tmp[n-1-j][i];
}

void tilt(int dir) {  //각 방향으로 기울인 결과 확인 (배열을 rotate해가며 왼쪽으로 기울임)
    while(dir--) rotate();
    for(int i=0; i<n; i++) { //각 줄에 대하여 왼쪽으로 기울인 결과 확인
        int tilted[21] = {0, };
        int idx = 0; //배열에 블록을 삽입할 위치의 인덱스 값
        for(int j=0; j<n; j++) { //각 칸에 대하여
            if(board2[i][j] == 0) continue; //원래 블록이 없는 경우
            if(tilted[idx] == 0) tilted[idx] = board2[i][j]; //삽입할 위치가 비어있는 경우, 이동
            else if(tilted[idx] == board2[i][j]) { //같은 값을 갖는 블록이 충돌
                tilted[idx] *= 2;
                idx++;
            }
            else { //다른 값을 갖는 블록이 충돌
                idx++;
                tilted[idx] = board2[i][j];
            }
        }
        for(int j=0; j<n; j++) board2[i][j] = tilted[j]; // 각 줄마다 결과 덮어씀
    }
}


int main(void) {
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin >> board[i][j];

    for(int tmp=0; tmp < 1<<(2*5); tmp++) { //가능한 모든 경우 확인
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) board2[i][j] = board[i][j];
        int num = tmp;
        for(int cnt=0; cnt<5; cnt++) { // 5번 움직임
            int dir = num % 4;
            num /= 4;
            tilt(dir);
        }
        //최댓값 확인
        for(int i=0; i<n; i++) 
            for(int j=0; j<n; j++) ans = max(ans, board2[i][j]);
    }
    cout << ans;

    return 0;
}
