#include <iostream>
using namespace std;

int n, num[101];
long long dp[101][21]; //dp[i][j] : i번째 숫자까지 더해서 j 숫자를 만들 수 있는 등식의 수

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> num[i];

    //n <= 100이기 때문에 1초 안에 백트래킹은 불가능 => DP
    dp[1][num[1]] = 1;
    for(int i=2; i<n; i++) { //마지막 수는 결과 값이므로 확인 안함
        for(int j=0; j<=20; j++) {
            if(j + num[i] <= 20) dp[i][j+num[i]] += dp[i-1][j];
            if(j - num[i] >= 0) dp[i][j-num[i]] += dp[i-1][j];
        }
    }
    cout << dp[n-1][num[n]]; //n-1번째 숫자까지 더해서 n번째 숫자를 만들 수 있는 등식의 수

    return 0;
}
