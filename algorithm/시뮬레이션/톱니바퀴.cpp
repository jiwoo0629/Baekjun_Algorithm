#include <iostream>
#include <string>
using namespace std;

string gear[5]; //0 : n극, 1 : s극
bool p[5]; //각 톱니바퀴 별로 회전되는지 유무

void turn(int n, int c) {
    if(c == 1) {
        char tmp = gear[n][7];
        for(int i=7; i>0; i--) gear[n][i] = gear[n][i-1];
        gear[n][0] = tmp;
    }
    else if(c == -1) {
        char tmp = gear[n][0];
        for(int i=0; i<7; i++) gear[n][i] = gear[n][i+1];
        gear[n][7] = tmp;
    }
}

void rotate(int n) {
    p[n] = true;
    if(n == 1) {
        for(int i=2; i<=4; i++) {
            if(p[i-1] == false) continue;
            p[i] = (gear[i-1][2] != gear[i][6]) ? true : false;
        }
    }
    else if(n == 4) {
        for(int i=3; i>=1; i--) {
            if(p[i+1] == false) continue;
            p[i] = (gear[i][2] != gear[i+1][6]) ? true : false;
        }
    }
    else { //n==2 or 3
        for(int i=n-1; i>=1; i--) {
            if(p[i+1] == false) continue;
            p[i] = (gear[i][2] != gear[i+1][6]) ? true : false;
        }
        for(int i=n+1; i<=4; i++) {
            if(p[i-1] == false) continue;
            p[i] = (gear[i-1][2] != gear[i][6]) ? true : false;
        }
    }
}

int main(void) {
    int k;
    for(int i=1; i<=4; i++) cin >> gear[i];
    cin >> k;
    while(k--) {
        int n, m; //n : 톱니바퀴 번호, m : 회전방향(1 : 시계, -1 : 반시계)
        cin >> n >> m;
        for(int i=1; i<=4; i++) p[i] = false;
        rotate(n);
        turn(n, m);
        int num1 = n-1, num2 = n+1; //좌우 다음으로 확인할 톱니바퀴 방향
        int c = (m == 1) ? -1 : 1; //다음 회전방향
        while(num1 > 0 || num2 <= 4) {
            if(num1 > 0 && p[num1] == true) 
                turn(num1, c);
            if(num2 <= 4 && p[num2] == true) 
                turn(num2, c);
            num1--;
            num2++;
            c = (c == 1) ? -1 : 1;
        }
    }
    
    int score = 0;
    for(int i=1; i<=4; i++) 
        if(gear[i][0] == '1') score += (1 << (i-1));
    cout << score;

    return 0;
}
