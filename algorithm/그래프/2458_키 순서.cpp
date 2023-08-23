#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a, b, answer = 0; //n : 학생 수 (~500), m : 비교횟수 (~125000)
int arr[501][501]; //인접행렬
int result[501];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++) fill(arr[i]+1, arr[i]+n+1, 125001);
    while(m--) { 
        cin >> a >> b; //a가 b보다 작음
        arr[a][b] = 1;
    }
    for(int k=1; k<=n; k++) { //500 * 500 * 500 = 62500000
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) 
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i == j || arr[i][j] != 125001 || arr[j][i] != 125001)
                result[i]++;
        }
        if(result[i] == n)
            answer++;
    }
    cout << answer;

    return 0;
}
