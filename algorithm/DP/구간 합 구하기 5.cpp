#include <iostream>
using namespace std;

int n, m;
int board[1030][1030];
int s[1030][1030];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    cin >> n >> m;
    for(int i=1; i<=n; i++) 
        for(int j=1; j<=n; j++) cin >> board[i][j];
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(j == 1) s[i][j] = board[i][j];
            else s[i][j] = s[i][j-1] + board[i][j];
        }
    }
    while(m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2; 
        int sum = 0;
        for(int i=1; i<=x2; i++) sum += s[i][y2]; 
        for(int i=1; i<x1; i++) sum -= s[i][y2]; 
        for(int i=x1; i<=x2; i++) sum -= s[i][y1-1]; 
        cout << sum << "\n";
    }

    return 0;
}
