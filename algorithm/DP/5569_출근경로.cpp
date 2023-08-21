#include <iostream>
using namespace std; 

/*
0   1   1   
1   2   2
1   2   3
1   2   5           
*/

int w, h, dp[2][102][102]; //직전에 꺽이지 않은 경우, 직전에 꺽인 경우

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h;
    dp[0][1][1] = dp[1][1][1] = 1;
    for(int i=1; i<=w; i++) {
        for(int j=1; j<=h; j++) {
            int now = dp[0][i][j] % 100000;
            dp[0][i+1][j] += now;
            dp[1][i+1][j+1] += now;
            now = dp[1][i][j] % 100000;
            dp[1][i][j+1] += now;
            dp[0][i+1][j+1] += now;

            dp[0][i][j] %= 100000;
            dp[1][i][j] %= 100000;
        }
    }

    cout << (dp[0][w][h]+dp[1][w][h]) % 100000;

    return 0;
}
