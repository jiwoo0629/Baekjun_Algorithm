#include <iostream>
using namespace std;

int n, k;
int cnt[1005][1005]; //n개 중 k개 고르는 경우의 수

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    cin >> n >> k;
    for(int i=1; i<=n; i++) cnt[i][1] = i;
    for(int i=4; i<=n; i++) {
        for(int j=2; j<=k; j++) {
            if(j > i/2) break; //전체 색의 절반 이상을 선택하는 경우의 수는 0
            //i-1개 중에 j개 선택 + i-2개 중에 j-1개 선택
            cnt[i][j] = (cnt[i-1][j] + cnt[i-2][j-1]) % 1000000003;
        }
    }
    cout << cnt[n][k];

    return 0;
}
