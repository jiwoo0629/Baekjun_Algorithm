#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int dp[201][201];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k; //n : a개수(~100), m : z개수(~100), k : 문자열 순서(~10억)
    cin >> n >> m >> k;
    /*
        첫 문자가 'a'인 문자열의 수 : 총 길이 n+m-1 중 m개가 'z'인 경우 => n+m+1Cm
        첫 문자가 'z'인 문자열의 수 : 총 길이 n+m-1 중 m-1개가 'z'인 경우 => n+m+1Cm-1
    */
    for(int i=0; i<=n+m; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    for(int i=1; i<=n+m; i++) {
        for(int j=1; j<i; j++) {
            if(dp[i-1][j] > 1000000000 || dp[i-1][j-1] > 1000000000)
                dp[i][j] = 1000000001; 
            else if(dp[i-1][j] + dp[i-1][j-1] > 1000000000) 
                dp[i][j] = 1000000001;
            else dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    if(dp[n+m][m] < k) {
        cout << -1;
        return 0;
    }

    string str = "";
    int nm = n + m;
    while(nm) {
        if(k <= dp[nm-1][n-1]) {
            str += "a";
            n--;
        }
        else {
            str += "z";
            k -= dp[nm-1][n-1];
            m--;
        }
        nm--;
    }
    cout << str;

    return 0;
}
