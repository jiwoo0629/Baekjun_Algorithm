#include <bits/stdc++.h>
using namespace std;

/*
    테이블 정의하기
    RGB[i][0] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 빨강
    RGB[i][1] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 초록
    RGB[i][2] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 파랑

    점화식 찾기
    RGB[k][0] = min(RGB[k-1][1], RGB[k-1][2]) + R[k];
    RGB[k][1] = min(RGB[k-1][0], RGB[k-1][2]) + G[k];
    RGB[k][2] = min(RGB[k-1][0], RGB[k-1][1]) + B[k];
*/

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int RGB[1001][3];
    int cost[1001][3];
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++) cin >> RGB[i][j];
    
    cost[1][0] = RGB[1][0];
    cost[1][1] = RGB[1][1];
    cost[1][2] = RGB[1][2];
    for (int i = 2; i <= n; i++) {
        cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + RGB[i][0];
        cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + RGB[i][1];
        cost[i][2] = min(cost[i - 1][0], cost[i - 1][1]) + RGB[i][2];
    }
    cout << min({ cost[n][0], cost[n][1], cost[n][2] });
    return 0;
}
