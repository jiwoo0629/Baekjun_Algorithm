#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//가로 1~9, 세로 1~9, 3*3 정사각형 1~9 => 각각 합 : 45
int board[9][9]; //스도쿠 판
vector<pair<int, int>> zero; //값이 0인 좌표
bool sudoku = false; //스도쿠 판이 완성되었는지 여부

bool check(pair<int, int> cur) { //이 칸을 채울 수 있는지 없는지 확인하는 함수
    int x = cur.first / 3, y = cur.second / 3;
    for(int i=0; i<9; i++) {
        //같은 가로 줄에 같은 숫자가 있는 경우, False
        if(board[cur.first][i] == board[cur.first][cur.second] && i != cur.second)
            return false;
        //같은 세로 줄에 같은 숫자가 있는 경우, False
        if(board[i][cur.second] == board[cur.first][cur.second] && i != cur.first)
            return false;
    }
    for(int i = 3*x; i<3*x + 3; i++) {
        for(int j=3*y; j<3*y + 3; j++) {
            //네모 안에 같은 숫자가 있는 경우
            if(board[i][j] == board[cur.first][cur.second]) {
                if(i != cur.first && j != cur.second)
                    return false;
            }
        }
    }
    //나머지 경우, True
    return true;
}

void func(int k) {
    if(k == zero.size()) { //스도쿠 판을 모두 다 채운 경우
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) cout << board[i][j] << " ";
            cout << "\n";
        }
        sudoku = true;
        return;
    }
    for(int i=1; i<=9; i++) {
        board[zero[k].first][zero[k].second] = i;
        if(check(zero[k])) func(k+1);
        if(sudoku) return;
    }   
    board[zero[k].first][zero[k].second ] = 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0) zero.push_back({i, j}); 
        }
    }
    
    func(0);
    
    return 0;
}
