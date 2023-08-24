#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n, r, c;
pair<int, int> matrix[501];
int sum[501][501];

int main(void) {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> r >> c;
        matrix[i] = {r, c};
    }
    for(int i=1; i<n; i++) { //곱하는 행렬의 수
        for(int j=1; i+j<=n; j++) { //n-k+1 : k개를 이용해서 곱하는 횟수
            sum[j][i+j] = INT_MAX; //일단 최댓값으로 초기화
            for(int k=j; k <= i+j; k++) {
                //j에서 k까지 && k+1에서 끝까지의 최솟값 + j 행렬의 행 * k 행렬의 열 * 끝 행렬의 열
                int cost = sum[j][k] + sum[k+1][i+j] + (matrix[j].first * matrix[k].second * matrix[i+j].second); 
                sum[j][i+j] = min(sum[j][i+j], cost);
            }
        }
    }
    cout << sum[1][n];

    return 0;
}
