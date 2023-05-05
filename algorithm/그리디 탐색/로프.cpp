#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long rope[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    cin >> n;
    for(int i=0; i<n; i++) cin >> rope[i];
    sort(rope, rope+n);

    long long mx = 0;
    for(int i=1; i<=n; i++) 
        mx = max(mx, rope[n-i] * i); 
    cout << mx;

    return 0;
}
