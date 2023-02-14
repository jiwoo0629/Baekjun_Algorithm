#include <iostream>
#include <cmath>
using namespace std;

int n;
int stair[101][10];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    
    cin >> n;
    for(int i=1; i<=9; i++) stair[1][i] = 1;
    for(int i=2; i<=n; i++) {
        for(int j=0; j<=9; j++) {
            if(j == 0) stair[i][j] = stair[i-1][1];
            else if(j == 9) stair[i][j] = stair[i-1][8];
            else stair[i][j] = (stair[i-1][j-1] + stair[i-1][j+1]) % 1000000000;
        }
    }
    long long result = 0;
    for(int i=0; i<=9; i++) result += stair[n][i];
    cout << result % 1000000000;

   return 0;
}
