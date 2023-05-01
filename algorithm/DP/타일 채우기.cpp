#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long tile[31];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if(n % 2 == 1) {
        cout << 0;
        return 0;
    }    
    tile[0] = 1; tile[2] = 3; 
    for(int i=2; i<=15; i++) {
        tile[2*i] = tile[2*(i-1)] * 3;
        for(int j=i-2; j>=0; j--) tile[2*i] += tile[2*j] * 2;
    }
    cout << tile[n];
    
    return 0;
}
