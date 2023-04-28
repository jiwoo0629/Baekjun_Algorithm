#include <iostream>
using namespace std;

int n;
long long upper[1005][10];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<=9; i++) upper[1][i] = i+1;
    
    for(int i=2; i<=n; i++) {
        upper[i][0] = 1;
        for(int j=1; j<=9; j++) upper[i][j] = (upper[i-1][j] + upper[i][j-1]) % 10007;
    }
    cout << upper[n][9] % 10007;
    
    return 0;
}

//1 2 3 4 5 6 7 8 9 10
//1 3 6 10 15 21 28 36 45 55
//1 4 10 20 35 56 84 120 165 220
