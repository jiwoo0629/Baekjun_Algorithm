#include <iostream>
using namespace std;

int n, k;
int coin[11];
int cnt = 0;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> coin[i];
    int a = n-1;
    while(k > 0) { 
        while(coin[a] > k) a--; 
        k -= coin[a]; 
        cnt++;
    }
    cout << cnt;

    return 0;
}
