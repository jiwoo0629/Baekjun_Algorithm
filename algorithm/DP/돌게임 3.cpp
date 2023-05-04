#include <iostream>
using namespace std;

int n;
int win[1005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    cin >> n;
    win[1] = win[3] = win[4] = 1; //SK 승
    win[2] = 2; //CY 승
    for(int i=5; i<=n; i++) {
        if(win[i-1] == 2 || win[i-3] == 2 || win[i-4] == 2) win[i] = 1;
        else win[i] = 2;
    }
    if(win[n] == 1) cout << "SK";
    else cout << "CY";

    return 0;
}
