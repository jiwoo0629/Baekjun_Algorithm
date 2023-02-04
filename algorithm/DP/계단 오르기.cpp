#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int stair[301];
    int score[301][3];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> stair[i];
    if (n == 1) {
        cout << stair[1];
        return 0;
    }
    score[1][1] = stair[1];
    score[1][2] = 0;
    score[2][1] = stair[2];
    score[2][2] = stair[1] + stair[2];
    for (int i = 3; i <= n; i++) {
        score[i][1] = max(score[i-2][1], score[i-2][2]) + stair[i]; //두 칸 띄워서 오르는 경우
        score[i][2] = score[i - 1][1] + stair[i]; //연속된 칸 오르는 경우 (3번 연속 x)
    }
    cout << max(score[n][1], score[n][2]);

    return 0;
}   
